#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <stdio.h>
#include <string.h>
int main() {
  char str[] = "memmove can be vvery useful....!";
assert(17 >= 0);
  memmove(str + 15, str + 16, 17);
  puts(str);
  return 0;
}
