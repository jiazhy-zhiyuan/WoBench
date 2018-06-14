#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <iostream>
template <int i>
void printText(const char (&text)[i]) {
  std::cout << text;
}
int main() {
  printText("some string constant");
  return 0;
}
