#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <stdlib.h>

/* stub for archs that lack dynamic linker support */

void _start()
{
	_Exit(1);
}
