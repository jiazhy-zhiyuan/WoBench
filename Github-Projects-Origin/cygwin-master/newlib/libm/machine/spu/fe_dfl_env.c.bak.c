#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <fenv.h>
/*
 * Define for FE_DFL_ENV macro, all bits zero.
 */
const fenv_t __fe_dfl_env = { 0 };
