#include <stdio.h>
#define MAXLINE 1000

void expand(char s1[], char s2[]);

int main() {
  char s1[MAXLINE] = "-a-e-0-3";
  char s2[MAXLINE];

  expand(s1, s2);

  printf("%s\n", s2);
}

void expand(char s1[], char s2[]) {
  int i, j = 0;

  for (i = 0; s1[i] != '\0'; i++) {
    if (s1[i] != '-' || (i == 0 || s1[i + 1] == '\0')) {
      s2[j++] = s1[i];
    } else {
      char start = s1[i - 1];
      char end = s1[i + 1];
      if ((start >= 'a' && end <= 'z' && start < end) ||
          (start >= 'A' && end <= 'Z' && start < end) ||
          (start >= '0' && end <= '9' && start < end)) {
        for (char c = start + 1; c < end; c++) {
          s2[j++] = c;
        }
      }
    }
  }

  s2[j] = '\0';
}
