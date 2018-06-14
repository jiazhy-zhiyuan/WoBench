#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include "pthread_impl.h"

int pthread_attr_init(pthread_attr_t *a)
{
	*a = (pthread_attr_t){0};
	return 0;
}
