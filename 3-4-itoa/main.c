#include <limits.h>
#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

void reverse(char s[]);
void itoa(int n, char s[]);

int main() {
  int n;
  char s[MAXLINE];

  printf("Enter a number: ");
  scanf("%d", &n);

  itoa(n, s);

  printf("n = %d\n", n);
  printf("s = %s\n", s);
}

void reverse(char s[]) {
  int c, i, j;

  for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

void itoa(int n, char s[]) {
  int i, sign;
  _Bool is_min_int_value = 0;

  if ((sign = n) < 0) {
    if (n == INT_MIN) {
      is_min_int_value = 1;
    } else {
      n = -n;
    }
  }
  i = 0;
  if (is_min_int_value) {
    do {
      s[i++] = -(n % 10) + '0';
    } while ((n /= 10) < 0);
    s[i++] = '-';
  } else {
    do {
      s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0) {
      s[i++] = '-';
    }
  }
  s[i] = '\0';
  reverse(s);
}
