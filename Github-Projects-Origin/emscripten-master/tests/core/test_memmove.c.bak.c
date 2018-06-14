#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <stdio.h>
#include <string.h>
int main() {
  char str[] = "memmove can be very useful....!";
assert(11 >= 0);
  memmove(str + 20, str + 15, 11);
  puts(str);
  return 0;
}
