#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <math.h>
#include "libc.h"

int __signgam = 0;

weak_alias(__signgam, signgam);
