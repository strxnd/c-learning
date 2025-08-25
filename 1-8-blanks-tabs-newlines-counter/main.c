#include <stdio.h>

int main() {
  int c, newlines = 0, tabs = 0, blanks = 0;

  while ((c = getchar()) != EOF) {
    if (c == '\n') {
      ++newlines;
    } else if (c == ' ') {
      ++blanks;
    } else if (c == '\t') {
      ++tabs;
    }
  }

  printf("newlines: %d\n", newlines);
  printf("tabs = %d\n", tabs);
  printf("blanks = %d\n", blanks);
}
