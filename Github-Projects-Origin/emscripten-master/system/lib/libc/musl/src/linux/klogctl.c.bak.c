#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <sys/klog.h>
#include "syscall.h"

int klogctl (int type, char *buf, int len)
{
	return syscall(SYS_syslog, type, buf, len);
}
