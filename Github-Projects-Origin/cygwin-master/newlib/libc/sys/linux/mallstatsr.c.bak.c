#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <stdlib.h>

void
_malloc_stats_r (struct _reent *ptr)
{
  malloc_stats ();
}
