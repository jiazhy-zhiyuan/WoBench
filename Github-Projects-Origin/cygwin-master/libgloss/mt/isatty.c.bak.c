#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <_ansi.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "trap.h"


isatty (fd)
     int fd;
{
  return 1;
}
