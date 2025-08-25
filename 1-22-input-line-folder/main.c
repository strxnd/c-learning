#include <stdio.h>
#define MAX_COLUMNS_PER_LINE 20

int main() {
  int c;
  int column_counter = 0;
  int last_non_blank = -1;

  while ((c = getchar()) != EOF) {
    if (c == '\n') {
      putchar('\n');
      column_counter = 0;
      last_non_blank = -1;
    } else {
      putchar(c);
      if (c != ' ' && c != '\t') {
        last_non_blank = column_counter;
      }
      column_counter++;

      if (column_counter > MAX_COLUMNS_PER_LINE) {
        if (last_non_blank == -1) {
          putchar('\n');
        } else {
          printf("\n");
          column_counter = column_counter - last_non_blank - 1;
          last_non_blank = -1;
        }
      }
    }
  }
}
