#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include "headers/fesetexceptflag.h"

void fesetexceptflag(const fexcept_t *flagp, int excepts)
{
    _fesetexceptflag(flagp, excepts);
}
