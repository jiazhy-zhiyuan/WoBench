#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
int
creat(path, mode)
     const char *path;
     int mode;
{
  return _creat (path, mode);
}
