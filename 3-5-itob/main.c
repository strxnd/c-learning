#include <limits.h>
#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

void reverse(char s[]);
void itoa(int n, char s);
void itob(int n, char s[], int b);

int main() {
  int n = 255;
  char s[MAXLINE];
  int b = 16;

  itob(n, s, b);
  printf("%d converted into base %d is %s.\n", n, b, s);
}

void reverse(char s[]) {
  int c, i, j;

  for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

void itob(int n, char s[], int b) {
  int i;

  i = 0;
  do {
    if (b <= 10) {
      s[i++] = n % b + '0';
    } else {
      s[i++] = (n % b) - 10 + 'A';
    }
  } while ((n /= b) != 0);
  s[i] = '\0';
  reverse(s);
}
