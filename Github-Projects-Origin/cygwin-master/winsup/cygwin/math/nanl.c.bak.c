#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
long double
nanl (const char *tagp)
{
  return __builtin_nanl ("");
}
