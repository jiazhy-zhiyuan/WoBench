#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
/* connector for unlink */

#include <reent.h>
#include <unistd.h>

int
unlink (const char *file)
{
  return _unlink_r (_REENT, file);
}
