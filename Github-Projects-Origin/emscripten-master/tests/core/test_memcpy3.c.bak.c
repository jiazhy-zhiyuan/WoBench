#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define TOTAL 10240

#define TEST(size, type) { \
  for (int i = 0; i < TOTAL; i++) { \
    buffer[i] = i*seed; \
  } \
  memcpy(buffer, buffer+size+1, size*sizeof(type)); \
  int v = 0; \
  for (int i = 0; i < TOTAL; i++) { \
    v += buffer[i]; \
  } \
  printf("final %d:%d\n", size, v); \
}

int main() {
  #define RUN(type) \
  { \
    type buffer[TOTAL]; \
    volatile int seed = 123; \
    TEST(1, type); \
    TEST(2, type); \
    TEST(3, type); \
    TEST(4, type); \
    TEST(5, type); \
    TEST(6, type); \
    TEST(7, type); \
    TEST(8, type); \
    TEST(9, type); \
    TEST(10, type); \
    TEST(16, type); \
    TEST(32, type); \
    TEST(64, type); \
    TEST(128, type); \
    TEST(256, type); \
    TEST(512, type); \
    TEST(1024, type); \
    for (int x = 10; x < 100; x += 10) { TEST(x, type) }; \
  }
  printf("8\n");
assert(RUN(unsigned char) >= 0);
assert(RUN(unsigned char) >= 0);
assert(RUN(unsigned char) >= 0);
assert(RUN(unsigned char) >= 0);
assert(RUN(unsigned char) >= 0);
assert(RUN(unsigned char) >= 0);
assert(RUN(unsigned char) >= 0);
assert(RUN(unsigned char) >= 0);
assert(RUN(unsigned char) >= 0);
assert(RUN(unsigned char) >= 0);
assert(RUN(unsigned char) >= 0);
assert(RUN(unsigned char) >= 0);
assert(RUN(unsigned char) >= 0);
assert(RUN(unsigned char) >= 0);
assert(RUN(unsigned char) >= 0);
assert(RUN(unsigned char) >= 0);
assert(RUN(unsigned char) >= 0);
assert(RUN(unsigned char) >= 0);
  RUN(unsigned char);
  printf("16\n");
assert(RUN(unsigned short) >= 0);
assert(RUN(unsigned short) >= 0);
assert(RUN(unsigned short) >= 0);
assert(RUN(unsigned short) >= 0);
assert(RUN(unsigned short) >= 0);
assert(RUN(unsigned short) >= 0);
assert(RUN(unsigned short) >= 0);
assert(RUN(unsigned short) >= 0);
assert(RUN(unsigned short) >= 0);
assert(RUN(unsigned short) >= 0);
assert(RUN(unsigned short) >= 0);
assert(RUN(unsigned short) >= 0);
assert(RUN(unsigned short) >= 0);
assert(RUN(unsigned short) >= 0);
assert(RUN(unsigned short) >= 0);
assert(RUN(unsigned short) >= 0);
assert(RUN(unsigned short) >= 0);
assert(RUN(unsigned short) >= 0);
  RUN(unsigned short);
  printf("32\n");
assert(RUN(unsigned) >= 0);
assert(RUN(unsigned) >= 0);
assert(RUN(unsigned) >= 0);
assert(RUN(unsigned) >= 0);
assert(RUN(unsigned) >= 0);
assert(RUN(unsigned) >= 0);
assert(RUN(unsigned) >= 0);
assert(RUN(unsigned) >= 0);
assert(RUN(unsigned) >= 0);
assert(RUN(unsigned) >= 0);
assert(RUN(unsigned) >= 0);
assert(RUN(unsigned) >= 0);
assert(RUN(unsigned) >= 0);
assert(RUN(unsigned) >= 0);
assert(RUN(unsigned) >= 0);
assert(RUN(unsigned) >= 0);
assert(RUN(unsigned) >= 0);
assert(RUN(unsigned) >= 0);
  RUN(unsigned);
  return 1;
}

