#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <stdio.h>

int
fclean (FILE *fp)
{
  return fflush (fp);
}
