#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include "headers/feupdateenv.h"

void feupdateenv(const fenv_t *envp)
{
    _feupdateenv(envp);
}
