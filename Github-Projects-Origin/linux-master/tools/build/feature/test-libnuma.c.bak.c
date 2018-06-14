#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
// SPDX-License-Identifier: GPL-2.0
#include <numa.h>
#include <numaif.h>

int main(void)
{
	numa_available();

	return 0;
}
