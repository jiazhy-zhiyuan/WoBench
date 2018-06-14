#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <machine/syscall.h>

/* Stub.  */
int
_utime(const char *path, const struct utimbuf *times)
{
  return -1;
}
