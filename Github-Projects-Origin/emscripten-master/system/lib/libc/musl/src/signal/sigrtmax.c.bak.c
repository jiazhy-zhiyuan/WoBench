#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <signal.h>

int __libc_current_sigrtmax()
{
	return _NSIG-1;
}
