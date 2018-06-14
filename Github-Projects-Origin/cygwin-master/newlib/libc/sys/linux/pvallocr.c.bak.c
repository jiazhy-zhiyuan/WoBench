#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <stdlib.h>

void * 
_pvalloc_r (struct _reent *ptr, size_t bytes)
{
  return pvalloc (bytes);
}
