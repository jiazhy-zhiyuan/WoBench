#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <time.h>
#include <stdio.h>

int main() {
  time_t t = time(0);
  printf("time: %s\n", ctime(&t));
}
