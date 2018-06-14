#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include "headers/feraiseexcept.h"

void feraiseexcept(int excepts)
{
    _feraiseexcept(excepts);
}
