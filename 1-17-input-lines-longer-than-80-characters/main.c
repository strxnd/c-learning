#include <stdio.h>
#define MAXLINE 1000
#define CHAR_LIMIT 80

int getline_custom(char line[], int maxline);

int main() {
  char line[MAXLINE];

  while (getline_custom(line, MAXLINE) > 0) {
    int length = 0;
    while (line[length] != '\0') {
      length++;
    }

    if (length > CHAR_LIMIT) {
      printf("%s", line);
    }
  }

  return 0;
}

int getline_custom(char line[], int maxline) {
  int i = 0;
  int c;

  while (i < maxline - 1 && (c = getchar()) != EOF && c != '\n') {
    line[i++] = c;
  }

  if (c == '\n') {
    line[i++] = c;
  }

  line[i] = '\0';

  return i;
}
