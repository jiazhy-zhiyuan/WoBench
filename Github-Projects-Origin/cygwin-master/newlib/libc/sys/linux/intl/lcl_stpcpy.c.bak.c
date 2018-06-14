#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
char *
__stpcpy (dest, src)
     char *dest;
     const char *src;
{
  while ((*dest++ = *src++) != '\0')
    /* Do nothing. */ ;
  return dest - 1;
}

