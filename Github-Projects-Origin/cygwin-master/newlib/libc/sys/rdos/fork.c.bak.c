#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include "config.h"
#include <_ansi.h>
#include <_syslist.h>
#include <errno.h>

int fork()
{
  errno = ENOSYS;
  return -1;
}
