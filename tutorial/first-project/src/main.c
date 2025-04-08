/*
 * Author: Kumar Aarav
 * Purpose: This program prints out the user's favorite number to the screen
 */

#include <stdio.h>

int main() {
  int myFavoriteNumber = 0;

  printf("Please enter your favorite number\n");
  scanf("%d", &myFavoriteNumber);
  printf("You entered number: %d\n", myFavoriteNumber);

  return 0;
}
