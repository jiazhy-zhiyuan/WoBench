#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <stdlib.h>

void * 
_valloc_r (struct _reent *ptr, size_t bytes)
{
  return valloc (bytes);
}
