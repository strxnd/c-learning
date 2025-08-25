#include <stdio.h>
#define MAXLINE 1000

int main() {
  int c, i = 0;
  char s[MAXLINE];

  while (i < MAXLINE - 1) {
    c = getchar();

    if (c == '\n') {
      break;
    }
    if (c == EOF) {
      break;
    }

    s[i++] = c;
  }

  s[i] = '\0';

  printf("%s\n", s);
}
