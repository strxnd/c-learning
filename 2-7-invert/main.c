#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

int main() {
  unsigned x = 0b10101010; // Example input
  int p = 5;
  int n = 3;

  unsigned result = invert(x, p, n);

  printf("Result: %u\n", result); // Expected output should reflect the changes

  return 0;
}

unsigned invert(unsigned x, int p, int n) {
  return x ^ ((1U << n) - 1) << (p + 1 - n);
}
