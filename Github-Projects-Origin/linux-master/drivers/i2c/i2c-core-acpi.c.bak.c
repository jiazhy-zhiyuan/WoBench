#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
/*
 * Linux I2C core ACPI support code
 *
 * Copyright (C) 2014 Intel Corp, Author: Lan Tianyu <tianyu.lan@intel.com>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 */

#include <linux/acpi.h>
#include <linux/device.h>
#include <linux/err.h>
#include <linux/i2c.h>
#include <linux/list.h>
#include <linux/module.h>
#include <linux/slab.h>

#include "i2c-core.h"

struct i2c_acpi_handler_data {
	struct acpi_connection_info info;
	struct i2c_adapter *adapter;
};

struct gsb_buffer {
	u8	status;
	u8	len;
	union {
		u16	wdata;
		u8	bdata;
		u8	data[0];
	};
} __packed;

struct i2c_acpi_lookup {
	struct i2c_board_info *info;
	acpi_handle adapter_handle;
	acpi_handle device_handle;
	acpi_handle search_handle;
	int n;
	int index;
	u32 speed;
	u32 min_speed;
};

static int i2c_acpi_fill_info(struct acpi_resource *ares, void *data)
{
	struct i2c_acpi_lookup *lookup = data;
	struct i2c_board_info *info = lookup->info;
	struct acpi_resource_i2c_serialbus *sb;
	acpi_status status;

	if (info->addr || ares->type != ACPI_RESOURCE_TYPE_SERIAL_BUS)
		return 1;

	sb = &ares->data.i2c_serial_bus;
	if (sb->type != ACPI_RESOURCE_SERIAL_TYPE_I2C)
		return 1;

	if (lookup->index != -1 && lookup->n++ != lookup->index)
		return 1;

	status = acpi_get_handle(lookup->device_handle,
				 sb->resource_source.string_ptr,
				 &lookup->adapter_handle);
	if (!ACPI_SUCCESS(status))
		return 1;

	info->addr = sb->slave_address;
	lookup->speed = sb->connection_speed;
	if (sb->access_mode == ACPI_I2C_10BIT_MODE)
		info->flags |= I2C_CLIENT_TEN;

	return 1;
}

static const struct acpi_device_id i2c_acpi_ignored_device_ids[] = {
	/*
	 * ACPI video acpi_devices, which are handled by the acpi-video driver
	 * sometimes contain a SERIAL_TYPE_I2C ACPI resource, ignore these.
	 */
	{ ACPI_VIDEO_HID, 0 },
	{}
};

static int i2c_acpi_do_lookup(struct acpi_device *adev,
			      struct i2c_acpi_lookup *lookup)
{
	struct i2c_board_info *info = lookup->info;
	struct list_head resource_list;
	int ret;

	if (acpi_bus_get_status(adev) || !adev->status.present ||
	    acpi_device_enumerated(adev))
		return -EINVAL;

	if (acpi_match_device_ids(adev, i2c_acpi_ignored_device_ids) == 0)
		return -ENODEV;

	memset(info, 0, sizeof(*info));
	lookup->device_handle = acpi_device_handle(adev);

	/* Look up for I2cSerialBus resource */
	INIT_LIST_HEAD(&resource_list);
	ret = acpi_dev_get_resources(adev, &resource_list,
				     i2c_acpi_fill_info, lookup);
	acpi_dev_free_resource_list(&resource_list);

	if (ret < 0 || !info->addr)
		return -EINVAL;

	return 0;
}

static int i2c_acpi_get_info(struct acpi_device *adev,
			     struct i2c_board_info *info,
			     struct i2c_adapter *adapter,
			     acpi_handle *adapter_handle)
{
	struct list_head resource_list;
	struct resource_entry *entry;
	struct i2c_acpi_lookup lookup;
	int ret;

	memset(&lookup, 0, sizeof(lookup));
	lookup.info = info;
	lookup.index = -1;

	ret = i2c_acpi_do_lookup(adev, &lookup);
	if (ret)
		return ret;

	if (adapter) {
		/* The adapter must match the one in I2cSerialBus() connector */
		if (ACPI_HANDLE(&adapter->dev) != lookup.adapter_handle)
			return -ENODEV;
	} else {
		struct acpi_device *adapter_adev;

		/* The adapter must be present */
		if (acpi_bus_get_device(lookup.adapter_handle, &adapter_adev))
			return -ENODEV;
		if (acpi_bus_get_status(adapter_adev) ||
		    !adapter_adev->status.present)
			return -ENODEV;
	}

	info->fwnode = acpi_fwnode_handle(adev);
	if (adapter_handle)
		*adapter_handle = lookup.adapter_handle;

	/* Then fill IRQ number if any */
	INIT_LIST_HEAD(&resource_list);
	ret = acpi_dev_get_resources(adev, &resource_list, NULL, NULL);
	if (ret < 0)
		return -EINVAL;

	resource_list_for_each_entry(entry, &resource_list) {
		if (resource_type(entry->res) == IORESOURCE_IRQ) {
			info->irq = entry->res->start;
			break;
		}
	}

	acpi_dev_free_resource_list(&resource_list);

	acpi_set_modalias(adev, dev_name(&adev->dev), info->type,
			  sizeof(info->type));

	return 0;
}

static void i2c_acpi_register_device(struct i2c_adapter *adapter,
				     struct acpi_device *adev,
				     struct i2c_board_info *info)
{
	adev->power.flags.ignore_parent = true;
	acpi_device_set_enumerated(adev);

	if (!i2c_new_device(adapter, info)) {
		adev->power.flags.ignore_parent = false;
		dev_err(&adapter->dev,
			"failed to add I2C device %s from ACPI\n",
			dev_name(&adev->dev));
	}
}

static acpi_status i2c_acpi_add_device(acpi_handle handle, u32 level,
				       void *data, void **return_value)
{
	struct i2c_adapter *adapter = data;
	struct acpi_device *adev;
	struct i2c_board_info info;

	if (acpi_bus_get_device(handle, &adev))
		return AE_OK;

	if (i2c_acpi_get_info(adev, &info, adapter, NULL))
		return AE_OK;

	i2c_acpi_register_device(adapter, adev, &info);

	return AE_OK;
}

#define I2C_ACPI_MAX_SCAN_DEPTH 32

/**
 * i2c_acpi_register_devices - enumerate I2C slave devices behind adapter
 * @adap: pointer to adapter
 *
 * Enumerate all I2C slave devices behind this adapter by walking the ACPI
 * namespace. When a device is found it will be added to the Linux device
 * model and bound to the corresponding ACPI handle.
 */
void i2c_acpi_register_devices(struct i2c_adapter *adap)
{
	acpi_status status;

	if (!has_acpi_companion(&adap->dev))
		return;

	status = acpi_walk_namespace(ACPI_TYPE_DEVICE, ACPI_ROOT_OBJECT,
				     I2C_ACPI_MAX_SCAN_DEPTH,
				     i2c_acpi_add_device, NULL,
				     adap, NULL);
	if (ACPI_FAILURE(status))
		dev_warn(&adap->dev, "failed to enumerate I2C slaves\n");
}

const struct acpi_device_id *
i2c_acpi_match_device(const struct acpi_device_id *matches,
		      struct i2c_client *client)
{
	if (!(client && matches))
		return NULL;

	return acpi_match_device(matches, &client->dev);
}

static acpi_status i2c_acpi_lookup_speed(acpi_handle handle, u32 level,
					   void *data, void **return_value)
{
	struct i2c_acpi_lookup *lookup = data;
	struct acpi_device *adev;

	if (acpi_bus_get_device(handle, &adev))
		return AE_OK;

	if (i2c_acpi_do_lookup(adev, lookup))
		return AE_OK;

	if (lookup->search_handle != lookup->adapter_handle)
		return AE_OK;

	if (lookup->speed <= lookup->min_speed)
		lookup->min_speed = lookup->speed;

	return AE_OK;
}

/**
 * i2c_acpi_find_bus_speed - find I2C bus speed from ACPI
 * @dev: The device owning the bus
 *
 * Find the I2C bus speed by walking the ACPI namespace for all I2C slaves
 * devices connected to this bus and use the speed of slowest device.
 *
 * Returns the speed in Hz or zero
 */
u32 i2c_acpi_find_bus_speed(struct device *dev)
{
	struct i2c_acpi_lookup lookup;
	struct i2c_board_info dummy;
	acpi_status status;

	if (!has_acpi_companion(dev))
		return 0;

	memset(&lookup, 0, sizeof(lookup));
	lookup.search_handle = ACPI_HANDLE(dev);
	lookup.min_speed = UINT_MAX;
	lookup.info = &dummy;
	lookup.index = -1;

	status = acpi_walk_namespace(ACPI_TYPE_DEVICE, ACPI_ROOT_OBJECT,
				     I2C_ACPI_MAX_SCAN_DEPTH,
				     i2c_acpi_lookup_speed, NULL,
				     &lookup, NULL);

	if (ACPI_FAILURE(status)) {
		dev_warn(dev, "unable to find I2C bus speed from ACPI\n");
		return 0;
	}

	return lookup.min_speed != UINT_MAX ? lookup.min_speed : 0;
}
EXPORT_SYMBOL_GPL(i2c_acpi_find_bus_speed);

static int i2c_acpi_find_match_adapter(struct device *dev, void *data)
{
	struct i2c_adapter *adapter = i2c_verify_adapter(dev);

	if (!adapter)
		return 0;

	return ACPI_HANDLE(dev) == (acpi_handle)data;
}

static int i2c_acpi_find_match_device(struct device *dev, void *data)
{
	return ACPI_COMPANION(dev) == data;
}

static struct i2c_adapter *i2c_acpi_find_adapter_by_handle(acpi_handle handle)
{
	struct device *dev;

	dev = bus_find_device(&i2c_bus_type, NULL, handle,
			      i2c_acpi_find_match_adapter);
	return dev ? i2c_verify_adapter(dev) : NULL;
}

static struct i2c_client *i2c_acpi_find_client_by_adev(struct acpi_device *adev)
{
	struct device *dev;

	dev = bus_find_device(&i2c_bus_type, NULL, adev,
			      i2c_acpi_find_match_device);
	return dev ? i2c_verify_client(dev) : NULL;
}

static int i2c_acpi_notify(struct notifier_block *nb, unsigned long value,
			   void *arg)
{
	struct acpi_device *adev = arg;
	struct i2c_board_info info;
	acpi_handle adapter_handle;
	struct i2c_adapter *adapter;
	struct i2c_client *client;

	switch (value) {
	case ACPI_RECONFIG_DEVICE_ADD:
		if (i2c_acpi_get_info(adev, &info, NULL, &adapter_handle))
			break;

		adapter = i2c_acpi_find_adapter_by_handle(adapter_handle);
		if (!adapter)
			break;

		i2c_acpi_register_device(adapter, adev, &info);
		break;
	case ACPI_RECONFIG_DEVICE_REMOVE:
		if (!acpi_device_enumerated(adev))
			break;

		client = i2c_acpi_find_client_by_adev(adev);
		if (!client)
			break;

		i2c_unregister_device(client);
		put_device(&client->dev);
		break;
	}

	return NOTIFY_OK;
}

struct notifier_block i2c_acpi_notifier = {
	.notifier_call = i2c_acpi_notify,
};

/**
 * i2c_acpi_new_device - Create i2c-client for the Nth I2cSerialBus resource
 * @dev:     Device owning the ACPI resources to get the client from
 * @index:   Index of ACPI resource to get
 * @info:    describes the I2C device; note this is modified (addr gets set)
 * Context: can sleep
 *
 * By default the i2c subsys creates an i2c-client for the first I2cSerialBus
 * resource of an acpi_device, but some acpi_devices have multiple I2cSerialBus
 * resources, in that case this function can be used to create an i2c-client
 * for other I2cSerialBus resources in the Current Resource Settings table.
 *
 * Also see i2c_new_device, which this function calls to create the i2c-client.
 *
 * Returns a pointer to the new i2c-client, or NULL if the adapter is not found.
 */
struct i2c_client *i2c_acpi_new_device(struct device *dev, int index,
				       struct i2c_board_info *info)
{
	struct i2c_acpi_lookup lookup;
	struct i2c_adapter *adapter;
	struct acpi_device *adev;
	LIST_HEAD(resource_list);
	int ret;

	adev = ACPI_COMPANION(dev);
	if (!adev)
		return NULL;

	memset(&lookup, 0, sizeof(lookup));
	lookup.info = info;
	lookup.device_handle = acpi_device_handle(adev);
	lookup.index = index;

	ret = acpi_dev_get_resources(adev, &resource_list,
				     i2c_acpi_fill_info, &lookup);
	acpi_dev_free_resource_list(&resource_list);

	if (ret < 0 || !info->addr)
		return NULL;

	adapter = i2c_acpi_find_adapter_by_handle(lookup.adapter_handle);
	if (!adapter)
		return NULL;

	return i2c_new_device(adapter, info);
}
EXPORT_SYMBOL_GPL(i2c_acpi_new_device);

#ifdef CONFIG_ACPI_I2C_OPREGION
static int acpi_gsb_i2c_read_bytes(struct i2c_client *client,
		u8 cmd, u8 *data, u8 data_len)
{

	struct i2c_msg msgs[2];
	int ret;
	u8 *buffer;

	buffer = kzalloc(data_len, GFP_KERNEL);
	if (!buffer)
		return AE_NO_MEMORY;

	msgs[0].addr = client->addr;
	msgs[0].flags = client->flags;
	msgs[0].len = 1;
	msgs[0].buf = &cmd;

	msgs[1].addr = client->addr;
	msgs[1].flags = client->flags | I2C_M_RD;
	msgs[1].len = data_len;
	msgs[1].buf = buffer;

	ret = i2c_transfer(client->adapter, msgs, ARRAY_SIZE(msgs));
	if (ret < 0)
		dev_err(&client->adapter->dev, "i2c read failed\n");
	else
		memcpy(data, buffer, data_len);

	kfree(buffer);
	return ret;
}

static int acpi_gsb_i2c_write_bytes(struct i2c_client *client,
		u8 cmd, u8 *data, u8 data_len)
{

	struct i2c_msg msgs[1];
	u8 *buffer;
	int ret = AE_OK;

	buffer = kzalloc(data_len + 1, GFP_KERNEL);
	if (!buffer)
		return AE_NO_MEMORY;

	buffer[0] = cmd;
	memcpy(buffer + 1, data, data_len);

	msgs[0].addr = client->addr;
	msgs[0].flags = client->flags;
	msgs[0].len = data_len + 1;
	msgs[0].buf = buffer;

	ret = i2c_transfer(client->adapter, msgs, ARRAY_SIZE(msgs));
	if (ret < 0)
		dev_err(&client->adapter->dev, "i2c write failed\n");

	kfree(buffer);
	return ret;
}

static acpi_status
i2c_acpi_space_handler(u32 function, acpi_physical_address command,
			u32 bits, u64 *value64,
			void *handler_context, void *region_context)
{
	struct gsb_buffer *gsb = (struct gsb_buffer *)value64;
	struct i2c_acpi_handler_data *data = handler_context;
	struct acpi_connection_info *info = &data->info;
	struct acpi_resource_i2c_serialbus *sb;
	struct i2c_adapter *adapter = data->adapter;
	struct i2c_client *client;
	struct acpi_resource *ares;
	u32 accessor_type = function >> 16;
	u8 action = function & ACPI_IO_MASK;
	acpi_status ret;
	int status;

	ret = acpi_buffer_to_resource(info->connection, info->length, &ares);
	if (ACPI_FAILURE(ret))
		return ret;

	client = kzalloc(sizeof(*client), GFP_KERNEL);
	if (!client) {
		ret = AE_NO_MEMORY;
		goto err;
	}

	if (!value64 || ares->type != ACPI_RESOURCE_TYPE_SERIAL_BUS) {
		ret = AE_BAD_PARAMETER;
		goto err;
	}

	sb = &ares->data.i2c_serial_bus;
	if (sb->type != ACPI_RESOURCE_SERIAL_TYPE_I2C) {
		ret = AE_BAD_PARAMETER;
		goto err;
	}

	client->adapter = adapter;
	client->addr = sb->slave_address;

	if (sb->access_mode == ACPI_I2C_10BIT_MODE)
		client->flags |= I2C_CLIENT_TEN;

	switch (accessor_type) {
	case ACPI_GSB_ACCESS_ATTRIB_SEND_RCV:
		if (action == ACPI_READ) {
			status = i2c_smbus_read_byte(client);
			if (status >= 0) {
				gsb->bdata = status;
				status = 0;
			}
		} else {
			status = i2c_smbus_write_byte(client, gsb->bdata);
		}
		break;

	case ACPI_GSB_ACCESS_ATTRIB_BYTE:
		if (action == ACPI_READ) {
			status = i2c_smbus_read_byte_data(client, command);
			if (status >= 0) {
				gsb->bdata = status;
				status = 0;
			}
		} else {
			status = i2c_smbus_write_byte_data(client, command,
					gsb->bdata);
		}
		break;

	case ACPI_GSB_ACCESS_ATTRIB_WORD:
		if (action == ACPI_READ) {
			status = i2c_smbus_read_word_data(client, command);
			if (status >= 0) {
				gsb->wdata = status;
				status = 0;
			}
		} else {
			status = i2c_smbus_write_word_data(client, command,
					gsb->wdata);
		}
		break;

	case ACPI_GSB_ACCESS_ATTRIB_BLOCK:
		if (action == ACPI_READ) {
			status = i2c_smbus_read_block_data(client, command,
					gsb->data);
			if (status >= 0) {
				gsb->len = status;
				status = 0;
			}
		} else {
			status = i2c_smbus_write_block_data(client, command,
					gsb->len, gsb->data);
		}
		break;

	case ACPI_GSB_ACCESS_ATTRIB_MULTIBYTE:
		if (action == ACPI_READ) {
			status = acpi_gsb_i2c_read_bytes(client, command,
					gsb->data, info->access_length);
			if (status > 0)
				status = 0;
		} else {
			status = acpi_gsb_i2c_write_bytes(client, command,
					gsb->data, info->access_length);
		}
		break;

	default:
		dev_warn(&adapter->dev, "protocol 0x%02x not supported for client 0x%02x\n",
			 accessor_type, client->addr);
		ret = AE_BAD_PARAMETER;
		goto err;
	}

	gsb->status = status;

 err:
	kfree(client);
	ACPI_FREE(ares);
	return ret;
}


int i2c_acpi_install_space_handler(struct i2c_adapter *adapter)
{
	acpi_handle handle;
	struct i2c_acpi_handler_data *data;
	acpi_status status;

	if (!adapter->dev.parent)
		return -ENODEV;

	handle = ACPI_HANDLE(adapter->dev.parent);

	if (!handle)
		return -ENODEV;

	data = kzalloc(sizeof(struct i2c_acpi_handler_data),
			    GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	data->adapter = adapter;
	status = acpi_bus_attach_private_data(handle, (void *)data);
	if (ACPI_FAILURE(status)) {
		kfree(data);
		return -ENOMEM;
	}

	status = acpi_install_address_space_handler(handle,
				ACPI_ADR_SPACE_GSBUS,
				&i2c_acpi_space_handler,
				NULL,
				data);
	if (ACPI_FAILURE(status)) {
		dev_err(&adapter->dev, "Error installing i2c space handler\n");
		acpi_bus_detach_private_data(handle);
		kfree(data);
		return -ENOMEM;
	}

	acpi_walk_dep_device_list(handle);
	return 0;
}

void i2c_acpi_remove_space_handler(struct i2c_adapter *adapter)
{
	acpi_handle handle;
	struct i2c_acpi_handler_data *data;
	acpi_status status;

	if (!adapter->dev.parent)
		return;

	handle = ACPI_HANDLE(adapter->dev.parent);

	if (!handle)
		return;

	acpi_remove_address_space_handler(handle,
				ACPI_ADR_SPACE_GSBUS,
				&i2c_acpi_space_handler);

	status = acpi_bus_get_private_data(handle, (void **)&data);
	if (ACPI_SUCCESS(status))
		kfree(data);

	acpi_bus_detach_private_data(handle);
}
#endif /* CONFIG_ACPI_I2C_OPREGION */
