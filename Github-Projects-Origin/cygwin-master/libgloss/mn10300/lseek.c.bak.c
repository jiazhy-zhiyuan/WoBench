#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <_ansi.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/unistd.h>
#include "trap.h"


off_t
_lseek (int file,
	off_t ptr,
	int dir)
{
  return TRAP0 (SYS_lseek, file, ptr, dir);
}
