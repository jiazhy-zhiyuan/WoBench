#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include "headers/fegetenv.h"

void fegetenv(fenv_t *envp)
{
    _fegetenv(envp);
}
