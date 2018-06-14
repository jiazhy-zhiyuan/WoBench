#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <stdlib.h>
#include <netdb.h>

void freeaddrinfo(struct addrinfo *p)
{
	free(p);
}
