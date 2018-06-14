#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
/* connector for wait */

#include <reent.h>
#include <sys/wait.h>

pid_t
wait (int *status)
{
  return _wait_r (_REENT, status);
}
