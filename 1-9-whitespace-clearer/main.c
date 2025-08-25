#include <stdio.h>

int main() {
  int c, last_char = 0;

  while ((c = getchar()) != EOF) {
    if (c != ' ' || last_char != ' ') {
      putchar(c);
    }
    last_char = c;
  }
}
