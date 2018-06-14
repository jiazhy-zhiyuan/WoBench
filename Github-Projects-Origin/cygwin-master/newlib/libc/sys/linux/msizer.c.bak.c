#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <stdlib.h>

size_t 
_malloc_usable_size_r (struct _reent *ptr, void *mem)
{
  return malloc_usable_size (mem);
}
