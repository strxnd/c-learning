#include <stdio.h>
#define MAXLINE 1000

void escape(char s[], char t[]);

int main() {
  char s[MAXLINE] = "Hello\t\n World!";
  char t[MAXLINE];

  escape(s, t);

  printf("%s\n", t);
}

void escape(char s[], char t[]) {
  int i, j;

  for (i = j = 0; s[i] != '\0'; i++) {
    switch (s[i]) {
    case '\n':
      t[j++] = '\\';
      t[j++] = 'n';
      break;
    case '\t':
      t[j++] = '\\';
      t[j++] = 't';
      break;
    default:
      t[j++] = s[i];
      break;
    }
  }

  t[j] = '\0';
}
