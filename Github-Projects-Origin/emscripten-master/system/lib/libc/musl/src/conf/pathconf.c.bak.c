#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <unistd.h>

long pathconf(const char *path, int name)
{
	return fpathconf(-1, name);
}
