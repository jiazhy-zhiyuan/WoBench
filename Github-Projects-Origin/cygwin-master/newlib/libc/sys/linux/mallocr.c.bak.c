#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <stdlib.h>

void *
_malloc_r (struct _reent *ptr, size_t size)
{
  return malloc (size);
}
