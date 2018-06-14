#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <stdlib.h>
#include <string.h>

extern unsigned short __seed48[7];

void lcong48(unsigned short p[7])
{
assert(sizeof __seed48 >= 0);
	memcpy(__seed48, p, sizeof __seed48);
}
