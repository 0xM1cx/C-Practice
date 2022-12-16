#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice() {
  // Generate a random number between 1 and 6
  return (rand() % 6) + 1;
}

int main(void) {
  // Seed the random number generator with the current time
  srand(time(NULL));

  int money = 100; // Starting amount of money

  while (money > 0) {
    int roll1 = rollDice();
    int roll2 = rollDice();

    // Rule No.1: Get 7 on the first roll and win; get 11 or 2 and you lose.
    if (roll1 == 7) {
      printf("You won on the first roll!\n");
      money += 10;
    } else if (roll1 == 11 || roll1 == 2) {
      printf("You lost on the first roll!\n");
      money -= 10;
    } else {
      // Rule No.2: Get the total sum of the two on the first roll to win the second roll onward.
      int sum = roll1 + roll2;
      if (sum == roll1) {
        printf("You won on the second roll!\n");
        money += 10;
      }

      while (1) {
        roll1 = rollDice();
        roll2 = rollDice();
        sum = roll1 + roll2;

        // Rule No.3: Get 7 roll 2 onwards and lose
        if (sum == 7) {
          printf("You lost on a roll after the first roll!\n");
          money -= 10;
          break;
        }

        // Rule No.2: Get the total sum of the two on the first roll to win the second roll onward.
        if (sum == roll1) {
          printf("You won on a roll after the first roll!\n");
          money += 10;
        }

        printf("Your current amount of money is: %d\n", money);

        // Prompt the user for input
        printf("Enter 'y' to roll again, anything else to quit: ");
        char input[4];
        scanf("%s", input);
        if (input[0] != 'y') {
          break;
        }
      }
    }

    printf("Your current amount of money is: %d\n", money);

    // Rule No.4: if the player runs out of money, it will automatically display "Not enough money"
    if (money == 0) {
      printf("Not enough money\n");
      break;
    }

    // Prompt the user for input
    printf("Enter 'y' to play again, anything else to quit: ");
    char input[4];
    scanf("%s", input);
    if (input[0] != 'y') {
      break;
    }
  }

  return 0;
}