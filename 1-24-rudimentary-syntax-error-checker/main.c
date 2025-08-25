#include <stdio.h>

int main() {
  int c;
  _Bool in_braces = 1;
  _Bool in_brackets = 1;
  _Bool in_parentheses = 1;
  _Bool in_escape_sequence = 1;
  _Bool in_single_quote = 1;
  _Bool in_double_quote = 1;

  while ((c = getchar()) != EOF) {
    if (c == '{') {
      in_braces = 0;
    } else if (c == '}') {
      if (in_braces == 0) {
        in_braces = 1;
      } else {
        printf("} placed incorrectly\n");
      }
    } else if (c == '[') {
      in_brackets = 0;
    } else if (c == ']') {
      if (in_brackets == 0) {
        in_brackets = 1;
      } else {
        printf("] placed incorrectly\n");
      }
    } else if (c == '(') {
      in_parentheses = 0;
    } else if (c == ')') {
      if (in_parentheses == 0) {
        in_parentheses = 1;
      } else {
        printf(") placed incorrectly\n");
      }
    } else if (in_escape_sequence == 0) {
      if (c != 'n' && c != 't' && c != '\\' && c != '"' && c != '\'' &&
          c != '0' && c != 'a' && c != 'b' && c != 'r' && c != 'v' &&
          c != 'f' && c != '?') {
        printf("Invalid escape sequence\n");
      }
    } else if (c == '\'') {
      if (in_single_quote == 0) {
        in_single_quote = 1;
      } else {
        printf("\" placed incorrectly\n");
      }
    } else if (c == '"') {
      if (in_double_quote == 0) {
        in_double_quote = 1;
      } else {
        printf("\" placed incorrectly");
      }
    }
  }

  return 0;
}
