#include <stdio.h>

#define IN 1
#define OUT 0

int main() {
  int c, state, word_length;
  int word_lengths[256] = {0};

  state = OUT;
  word_length = 0;

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      if (state == IN) {
        state = OUT;
        if (word_length > 0) {
          word_lengths[word_length]++;
        }
        word_length = 0;
      }
    } else {
      state = IN;
      word_length++;
    }
  }

  if (state == IN && word_length > 0) {
    word_lengths[word_length]++;
  }

  printf("\nWord Length Histogram:\n");
  for (int i = 1; i < 256; i++) {
    if (word_lengths[i] > 0) {
      printf("%d: ", i);
      for (int j = 0; j < word_lengths[i]; j++) {
        printf("*");
      }
      printf("\n");
    }
  }
}
