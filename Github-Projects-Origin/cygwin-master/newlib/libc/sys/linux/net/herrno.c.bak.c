#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <reent.h>

int *__h_errno_location() {
  return &(_REENT->_new._reent._h_errno);
}

