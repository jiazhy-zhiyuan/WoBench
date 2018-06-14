#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#define _GNU_SOURCE
#include <sched.h>

int main(void)
{
	return setns(0, 0);
}
