#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
// avoid "array initializer too large" errors
#include <stdio.h>
#include <assert.h>

#define SIZE (1024 * 100)
struct Struct {
  char x;
  int y;
};
Struct buffy[SIZE];

int main() {
  for (int i = 0; i < SIZE; i++) {
    assert(buffy[i].x == 0 && buffy[i].y == 0);
  }  // we were zeroinitialized
  for (int i = 0; i < SIZE; i++) {
    buffy[i].x = i * i;
    buffy[i].y = i * i * i;
  }  // we can save data
  printf("*%d*\n", buffy[SIZE / 3].x);
  return 0;
}
