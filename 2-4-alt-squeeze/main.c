#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

void squeeze(char s1[], char s2[]);

int main() {
  char s1[MAXLINE], s2[MAXLINE];

  strcpy(s1, "hello world");
  strcpy(s2, "aeiou");
  squeeze(s1, s2);
  printf("Real result: %s\n", s1);
  printf("Expected result: hll wrld\n\n");

  strcpy(s1, "programming");
  strcpy(s2, "aeiou");
  squeeze(s1, s2);
  printf("Real result: %s\n", s1);
  printf("Expected result: prgrmmng\n\n");

  strcpy(s1, "abcdefg");
  strcpy(s2, "bdf");
  squeeze(s1, s2);
  printf("Real result: %s\n", s1);
  printf("Expected result: aceg\n\n");

  strcpy(s1, "testing123");
  strcpy(s2, "123");
  squeeze(s1, s2);
  printf("Real result: %s\n", s1);
  printf("Expected result: testing\n\n");

  strcpy(s1, "C programming");
  strcpy(s2, "Cpg");
  squeeze(s1, s2);
  printf("Real result: %s\n", s1);
  printf("Expected result:  rogrammin\n");
}

void squeeze(char s1[], char s2[]) {
  int i, j, x;
  _Bool found = 0;

  for (i = j = 0; s1[i] != '\0'; i++) {
    found = 0;
    for (x = 0; s2[x] != '\0'; x++) {
      if (s1[i] == s2[x]) {
        found = 1;
        break; // Found a match, break out of the inner loop
      }
    }
    if (!found) {
      s1[j++] = s1[i]; // Retain characters not in s2
    }
  }
  s1[j] = '\0';
}
