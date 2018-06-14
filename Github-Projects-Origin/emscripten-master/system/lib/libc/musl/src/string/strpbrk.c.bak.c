#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <string.h>

char *strpbrk(const char *s, const char *b)
{
	s += strcspn(s, b);
	return *s ? (char *)s : 0;
}
