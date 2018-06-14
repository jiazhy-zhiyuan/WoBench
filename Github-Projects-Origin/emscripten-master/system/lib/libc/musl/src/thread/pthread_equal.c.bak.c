#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <pthread.h>

int (pthread_equal)(pthread_t a, pthread_t b)
{
	return a==b;
}
