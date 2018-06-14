#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <stdlib.h>
#include <_ansi.h>

float
atoff (const char *s)
{
  return strtof (s, NULL);
}
