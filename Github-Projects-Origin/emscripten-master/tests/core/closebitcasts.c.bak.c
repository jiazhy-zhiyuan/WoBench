#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <stdio.h>

int main(int argc, char **argv) {
  float x = argc%17, y = (argc+1)*(argc+2)*(argc+3)*(argc+4)*(argc*5);
  y *= 1<<30;
  y *= -13;
  if (argc == 17) { x++; y--; }
  int *xi = (int*)&x;
  int *yi = (int*)&y;
  int z = *xi - *yi;
  while (z % 15) {
    z++;
  }
  printf("!%d\n", z);

  double xd = x, yd = y;
  yd = yd*yd;
  yd = yd*yd;
  int *xl = (int*)&xd;
  int *xh = &((int*)&xd)[1];
  int *yl = (int*)&yd;
  int *yh = &((int*)&yd)[1];
  int l = *xl - *yl;
  int h = *xh - *yh;
  while (l % 15) {
    l++;
    h += 3;
  }
  printf("%d,%d!\n", l, h);
  return 0;
}

