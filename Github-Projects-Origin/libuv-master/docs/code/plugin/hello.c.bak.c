#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include "plugin.h"

void initialize() {
    mfp_register("Hello World!");
}
