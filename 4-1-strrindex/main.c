#include <stdio.h>
#include <string.h>

int strrindex(char s[], char t[]);

int main() {
  // Test case: t appears once in s
  char s1[] = "hello world world";
  char t1[] = "world";
  printf("Test 1: %d (expected: 12)\n", strrindex(s1, t1));

  return 0;
}

int strrindex(char s[], char t[]) {
  int i, j, k;

  for (i = strlen(s) - 1; s[i] != '\0'; i--) {
    for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
      ;
    if (k > 0 && t[k] == '\0') {
      return i;
    }
  }
  return -1;
}
