#include <stdio.h>

int bitcount(unsigned x);

int main() {
  unsigned x = 10;

  printf("Result: %d\n", bitcount(x));
}

int bitcount(unsigned x) {
  int b;

  for (b = 0; x != 0; x &= (x - 1)) {
    b++;
  }

  return b;
}
