#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <stdlib.h>

void
_free_r (struct _reent *ptr, void *addr)
{
  free (addr);
}
