#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <stdlib.h>

void *
_realloc_r (struct _reent *ptr, void *old, size_t newlen)
{
  return realloc (old, newlen);
}
