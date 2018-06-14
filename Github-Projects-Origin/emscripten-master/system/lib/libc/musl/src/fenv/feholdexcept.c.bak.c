#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <fenv.h>

int feholdexcept(fenv_t *envp)
{
	fegetenv(envp);
	feclearexcept(FE_ALL_EXCEPT);
	return 0;
}
