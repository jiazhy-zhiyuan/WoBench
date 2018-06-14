#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
/* connector for close */

#include <reent.h>
#include <unistd.h>

int
close (int fd)
{
  return _close_r (_REENT, fd);
}
