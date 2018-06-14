#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include "pthread_impl.h"

void __vm_lock(int), __vm_unlock(void);

int pthread_barrier_destroy(pthread_barrier_t *b)
{
	if (b->_b_limit < 0) {
		if (b->_b_lock) {
			int v;
			a_or(&b->_b_lock, INT_MIN);
			while ((v = b->_b_lock) & INT_MAX)
				__wait(&b->_b_lock, 0, v, 0);
		}
		__vm_lock(-1);
		__vm_unlock();
	}
	return 0;
}
