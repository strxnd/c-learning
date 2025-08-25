#include <alloca.h>
#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int get_line(char line[], int maxline);
int length(char s[]);
void reverse(char s[]);

int main() {
  char line[MAXLINE];

  while (get_line(line, MAXLINE) > 0) {
    reverse(line);
    printf("%s\n", line);
  }

  return 0;
}

int get_line(char line[], int maxline) {
  int c, i;

  for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    line[i] = c;
  }

  line[i] = '\0';

  return i;
}

void reverse(char s[]) {
  int start = 0;
  int end = strlen(s) - 1;
  char temp;

  while (start < end) {
    temp = s[start];
    s[start] = s[end];
    s[end] = temp;

    start++;
    end--;
  }
}
