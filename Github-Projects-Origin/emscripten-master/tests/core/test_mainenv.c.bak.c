#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <stdio.h>
int main(int argc, char **argv, char **envp) {
  printf("*%p*\n", envp);
  return 0;
}
