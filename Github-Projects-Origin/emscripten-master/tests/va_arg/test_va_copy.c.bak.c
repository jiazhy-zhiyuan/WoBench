#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int arg_n(int n, va_list ap) {
  // similar to the implementation of vfscanf
  va_list ap2;
  va_copy(ap2, ap);
  for (int i = 0; i < n; ++i) {
    va_arg(ap2, int);
  }
  int ret = va_arg(ap2, int);
  va_end(ap2);
  return ret;
}

void vary(int n, ...)
{
  va_list v;
  va_start(v, n);

  for (int i = 0; i < n; ++i) {
    if (i != 0) {
      printf(", ");
    }
    printf("%d", arg_n(i, v));
  }
  printf("\n");
  va_end(v);
}

int main() {
  int x = 1;
  int y = 2;
  int z = 3;

  vary(3, x, y, z);
  vary(2, x, z);
  vary(1, x);
  return 0;
}
