#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <stddef.h>

size_t __ctype_get_mb_cur_max()
{
	return 4;
}
