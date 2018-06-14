#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include "pthread_impl.h"

void __testcancel(void);

void pthread_testcancel()
{
	__testcancel();
}
