#include <stdio.h>

unsigned rightrot(unsigned x, int n);

int main() {
  unsigned x = 0b10101010;
  int n = 2;

  unsigned result = rightrot(x, n);

  printf("Result: %u\n", result);
}

unsigned rightrot(unsigned x, int n) {
  n = n % (sizeof(x) * 8);

  return x >> n | (x & ((1 << n) - 1)) << ((sizeof(x) * 8) - n);
}
