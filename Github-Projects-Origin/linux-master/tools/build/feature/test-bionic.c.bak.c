#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
// SPDX-License-Identifier: GPL-2.0
#include <android/api-level.h>

int main(void)
{
	return __ANDROID_API__;
}
