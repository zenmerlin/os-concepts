#include <stdio.h>

int main()
{
  int i;
  printf("Introduction to loops incrementing i from 1 to 10\n");

  printf("This is a for loop...\n");
  for (i=1; i<=10; i++) {
    printf("%d ", i);
  }

  printf("\nThis is a while loop doing the same thing...\n");
  i = 1;
  while (i <= 10) {
    printf("%d ", i);
    i++;
  }

  printf("\nThis is a do while loop doing the same thing...\n");
  i = 1;
  do {
    printf("%d ", i);
    i++;
  } while (i != 11);

  // Press a key to exit
  getchar();
  return 0;
}
