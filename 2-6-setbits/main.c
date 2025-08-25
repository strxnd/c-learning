#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, int y);

int main() {
  unsigned x = 0b10101010; // Example input
  unsigned y = 0b11001100; // Example input
  int p = 5;
  int n = 3;

  unsigned result = setbits(x, p, n, y);

  printf("Result: %u\n", result); // Expected output should reflect the changes

  return 0;
}

unsigned setbits(unsigned x, int p, int n, int y) {
  return (x & ~(~(~0 << n) << (p - n + 1))) | y & ~(~0 << n) << (p - n + 1);
}
