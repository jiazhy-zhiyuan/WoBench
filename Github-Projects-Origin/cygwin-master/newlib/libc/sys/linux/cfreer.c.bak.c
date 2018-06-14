#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <stdlib.h>

void
_cfree_r (struct _reent *ptr, void *mem)
{
  return cfree (mem);
}
