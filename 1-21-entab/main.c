#include <stdio.h>
#define TAB_LENGTH 4

int main() {
  int c;
  int blank_counter = 0;

  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      ++blank_counter;
    }

    if (blank_counter != TAB_LENGTH) {
      while (blank_counter >= TAB_LENGTH) {
        putchar('\t');
        blank_counter -= TAB_LENGTH;
      }
      while (blank_counter > 0) {
        putchar(' ');
        --blank_counter;
      }
      putchar(c);
    }
  }
}
