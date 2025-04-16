#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Initialising the random number generator
  time_t t;
  srand((unsigned)time(&t));

  int randomNumber = rand() % 21; // Random number between 0 and 20
  int userGuess;
  int triesLeft;
  _Bool validInput;

  printf("This is a guessing game.\n");
  printf("I have chosen a number between 0 and 20 which you must guess.\n");

  do {
    for (triesLeft = 5; triesLeft > 0; triesLeft--) {
      if (triesLeft > 1) {
        printf("You have %d tries left.\n", triesLeft);
      } else {
        printf("You have %d try left.\n", triesLeft);
      }
      printf("Enter guess: ");
      scanf("%d", &userGuess);
      if (userGuess > 20 || userGuess < 0) {
        validInput = 0;
        printf("\nInput must be between 0 and 20.\n");
        triesLeft++;
        continue;
      } else if (randomNumber > userGuess) {
        validInput = 1;
        printf("\nThe number I have chosen is more than your guess.\n");
        continue;
      } else if (randomNumber < userGuess) {
        validInput = 1;
        printf("\nThe number I have chosen is less than your guess.\n");
        continue;
      } else {
        validInput = 1;
        printf("\nCongratulations! The correct answer was %d.\n", randomNumber);
        break;
      }
    }
    if (triesLeft == 0) {
      printf("\nSorry! You ran out of tries. The correct answer was %d.\n",
             randomNumber);
    }
  } while (!validInput);

  return 0;
}
