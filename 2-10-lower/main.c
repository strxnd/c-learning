#include <stdio.h>
#define MAXLINE 1000

void lower(char s[]);

int main() {
  char s[MAXLINE] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  lower(s);
  printf("%s\n", s);
}

void lower(char s[]) {
  for (int i = 0; s[i] != '\0'; i++) {
    s[i] = (s[i] >= 'A' && s[i] <= 'Z') ? s[i] + 32 : s[i];
  }
}
