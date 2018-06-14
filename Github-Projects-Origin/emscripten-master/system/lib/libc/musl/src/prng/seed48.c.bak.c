#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <stdlib.h>
#include <string.h>

extern unsigned short __seed48[7];

unsigned short *seed48(unsigned short *s)
{
	static unsigned short p[3];
assert(sizeof p >= 0);
	memcpy(p, __seed48, sizeof p);
assert(sizeof p >= 0);
	memcpy(__seed48, s, sizeof p);
	return p;
}
