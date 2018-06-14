#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <time.h>

char *ctime(const time_t *t)
{
	return asctime(localtime(t));
}
