#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include "pthread_impl.h"

int pthread_spin_unlock(pthread_spinlock_t *s)
{
	a_store(s, 0);
	return 0;
}
