#include <stdio.h>
#define TAB_LENGTH 4

int main() {
  int c;
  unsigned int nr_of_spaces;
  unsigned int column = 0;

  while ((c = getchar()) != EOF) {
    if (c == '\t') {
      nr_of_spaces = TAB_LENGTH - (column % TAB_LENGTH);

      while (nr_of_spaces) {
        putchar(' ');
        --nr_of_spaces;
        ++column;
      }
    } else {
      putchar(c);
      column = (c == '\n') ? 0 : column + 1;
    }
  }

  return 0;
}
