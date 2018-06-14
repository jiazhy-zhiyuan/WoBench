#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <unistd.h>
#include <time.h>

unsigned sleep(unsigned seconds)
{
	struct timespec tv = { .tv_sec = seconds, .tv_nsec = 0 };
	if (nanosleep(&tv, &tv))
		return tv.tv_sec;
	return 0;
}
