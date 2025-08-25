#include <stdio.h>
#define MAXLINE 1000

int any(char s1[], char s2[]);
void test(char s1[], char s2[], int expected_result);

int main() {
  test("abcdef", "xyz", -1);
  test("python", "ty", 1);
  test("hello", "ol", 2);
  test("abcd", "d", 3);
  test("", "abc", -1);
  test("test", "", -1);
  test("", "", -1);
  test("abcdef", "a", 0);
  test("!@#$%^", "%^&", 4);
  test("Hello", "hE", -1);
}

int any(char s1[], char s2[]) {
  int i, x;
  _Bool found = 0;

  for (i = 0; s1[i] != '\0'; i++) {
    for (x = 0; s2[x] != '\0'; x++) {
      if (s1[i] == s2[x]) {
        return i; // Return the index of the first match
      }
    }
  }

  return -1; // Return -1 if no match is found
}

void test(char s1[], char s2[], int expected_result) {
  if (any(s1, s2) == expected_result) {
    printf("Test passed for s1: %s, s2: %s\n", s1, s2);
  } else {
    printf("Test failed for s1: %s, s2: %s. Expected: %d, Got: %d\n", s1, s2,
           expected_result, any(s1, s2));
  }
}
