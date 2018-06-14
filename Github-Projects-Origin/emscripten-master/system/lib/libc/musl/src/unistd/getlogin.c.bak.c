#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <unistd.h>
#include <stdlib.h>

char *getlogin(void)
{
	return getenv("LOGNAME");
}
