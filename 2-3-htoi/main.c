#include <errno.h>
#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int htoi(char s[]);
int len(char s[]);

int main() {
  char s[MAXLINE];

  printf("Enter a hexadecimal value: ");
  scanf("%s", s);

  printf("Integer: %d\n", htoi(s));
}

int htoi(char s[]) {
  int converted_int = 0, i, warning = 0;
  char first_two_characters_of_s[3] = {s[0], s[1], '\0'};

  // Check if the hexadecimal begins with "0x" or "0X"
  if (strcmp(first_two_characters_of_s, "0x") == 0 ||
      strcmp(first_two_characters_of_s, "0X") == 0) {
    i = 2;
  } else {
    i = 0;
  }

  // Convert the hexadecimal string to an integer
  while (i < len(s)) {
    int digit;

    // Convert each character to its corresponding hexadecimal value
    if (s[i] >= '0' && s[i] <= '9') {
      digit = s[i] - '0';
    } else if (s[i] >= 'A' && s[i] <= 'F') {
      digit = s[i] - 'A' + 10;
    } else if (s[i] >= 'a' && s[i] <= 'f') {
      digit = s[i] - 'a' + 10;
    } else {
      // If the character is invalid, return an error or handle it as needed
      printf("Error: Invalid hexadecimal character '%c'\n", s[i]);
      warning = 1;
    }

    converted_int = (converted_int << 4) | digit;

    ++i;
  }
  if (warning == 1) {
    printf("Warning: Integer value below invalid\n");
  }

  return converted_int;
}

int len(char s[]) {
  int i;

  for (i = 0; s[i] != '\0'; ++i)
    ;

  return i;
}
