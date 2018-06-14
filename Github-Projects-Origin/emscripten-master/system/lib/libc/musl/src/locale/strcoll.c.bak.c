#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <string.h>
#include <locale.h>
#include "libc.h"

int __strcoll_l(const char *l, const char *r, locale_t loc)
{
	return strcmp(l, r);
}

int strcoll(const char *l, const char *r)
{
	return __strcoll_l(l, r, 0);
}

weak_alias(__strcoll_l, strcoll_l);
