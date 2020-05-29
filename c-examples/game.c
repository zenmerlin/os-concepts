#include <stdio.h>
#include <stdbool.h>

void play_game()
{
  printf("Play game called\n");
}

void load_game()
{
  printf("Load game called\n");
}

void save_game()
{
  printf("Save game called\n");
}

int main()
{
  char selection;
  bool input_invalid = true;
  printf(
      "===Main Menu===\n"
      "1. Play Game\n"
      "2. Load Game\n"
      "3. Save Game\n"
      "4. Exit\n\n"
      "Selection? "
  );
  
  while (input_invalid) {
    selection = getchar();
    switch (selection) {
      case '1':
        play_game();
        input_invalid = false;
        break;

      case '2':
        load_game();
        input_invalid = false;
        break;

      case '3':
        save_game();
        input_invalid = false;
        break;

      case '4':
        input_invalid = false;
        return 0;
        break;

      default:
        printf(
            "Bad input! Try again.\n"
            "Selection? "
        );
        break;
    }
  }

  return 0;
}
