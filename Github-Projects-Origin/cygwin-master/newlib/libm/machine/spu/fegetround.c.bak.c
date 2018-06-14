#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include "headers/fegetround.h"

int fegetround()
{
    return _fegetround();
}
