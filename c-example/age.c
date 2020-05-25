#include <stdio.h>

int main()
{
  int age;
  printf("How old are you? ");
  scanf("%d", &age);
  if (age > 100) {
    printf("\nSon, you should be dead.\n");
  } else if (age >= 75) {
    printf("\nYou dead yet?\n");
  } else if (age >= 65) {
    printf("\nBet you wish you could retire.\n");
  } else if (age >= 50) {
    printf("\nCan't wait to retire, eh?\n");
  } else if (age >= 40) {
    printf("\nLordy, lordy, over forty\n");
  } else if (age >= 30) {
    printf("\nMeh, that's not too old\n");
  } else if (age >= 20) {
    printf("\nYeah, the roaring 20's! Enjoy it while it lasts.\n");
  } else if (age >= 18) {
    printf("\nWelcome to adulthood! Here are your bills...\n");
  } else if (age > 13) {
    printf("\nHow's high school? Yeah, I didn't like it either.\n");
  } else {
    printf("\nYou is just a bebe! Did your mom type this for you?\n");
  }
  return 0;
}

