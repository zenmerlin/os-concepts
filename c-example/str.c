#include <stdio.h>
#include <string.h>

void input(char *str, int size)
{
  int i;
  fgets(str, size, stdin);

  /* Strip out newline character if there is one */
  for (i=0; i<size; i++) {
    if (str[i] == '\n') {
      str[i] = '\0';
      return;
    }
  }
}

int main()
{
  int size = 50;
  int full_size = size * 2 + 1;
  char first_name[size];
  char last_name[size];
  char full_name[full_size];

  printf("First name? ");
  input(first_name, size);

  printf("Last name? ");
  input(last_name, size);

  strcat(full_name, first_name);
  strcat(full_name, " ");
  strcat(full_name, last_name);

  printf("Hello, %s.\n", full_name);
  return 0;
}
