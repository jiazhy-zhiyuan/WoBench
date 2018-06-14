#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <string.h>

void *__memrchr(const void *, int, size_t);

char *strrchr(const char *s, int c)
{
	return __memrchr(s, c, strlen(s) + 1);
}
