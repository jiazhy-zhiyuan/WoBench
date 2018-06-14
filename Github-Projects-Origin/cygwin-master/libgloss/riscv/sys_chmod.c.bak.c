#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <machine/syscall.h>
#include <sys/types.h>

/* Stub.  */
int
_chmod(const char *path, mode_t mode)
{
  return -1;
}
