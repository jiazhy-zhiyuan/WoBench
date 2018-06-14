#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <dirent.h>
#include "__dirent.h"

long telldir(DIR *dir)
{
	return dir->tell;
}
