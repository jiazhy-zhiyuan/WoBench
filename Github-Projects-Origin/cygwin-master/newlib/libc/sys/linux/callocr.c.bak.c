#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <stdlib.h>

void *
_calloc_r (struct _reent *ptr, size_t size, size_t len)
{
  return calloc (size, len);
}
