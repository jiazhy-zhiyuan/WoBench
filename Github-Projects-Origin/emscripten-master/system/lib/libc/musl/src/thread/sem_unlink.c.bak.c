#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <semaphore.h>
#include <sys/mman.h>

int sem_unlink(const char *name)
{
	return shm_unlink(name);
}
