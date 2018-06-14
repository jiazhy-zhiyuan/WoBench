#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
// SPDX-License-Identifier: GPL-2.0
#include <libelf.h>

int main(void)
{
	size_t dst;

	return elf_getshdrstrndx(0, &dst);
}
