#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <machine/syscall.h>
#include <sys/types.h>

/* Stub.  */
int _chown(const char *path, uid_t owner, gid_t group)
{
  return -1;
}
