#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INITIAL_MONEY 100

int roll_dice() {
  return rand() % 6 + 1;
}

int main() {
  srand(time(NULL)); // seed the random number generator

  int money = INITIAL_MONEY;
  int bet;
  int roll1, roll2;

  while (money > 0) {
    printf("You have $%d. Enter bet amount: ", money);
    scanf("%d", &bet);

    if (bet > money) {
      printf("Not enough money.\n");
      continue;
    }

    roll1 = roll_dice() + roll_dice();
    printf("You rolled %d on the first roll.\n", roll1);

    if (roll1 == 7 || roll1 == 11) {
      printf("You win!\n");
      money += bet;
    } else if (roll1 == 2) {
      printf("You lose.\n");
      money -= bet;
    } else {
      int roll2 = roll_dice() + roll_dice();
      printf("You rolled %d on the second roll.\n", roll2);
      if (roll2 == 7) {
        printf("You lose.\n");
        money -= bet;
      } else if (roll2 == roll1) {
        printf("You win!\n");
        money += bet;
      } else {
        printf("Roll again.\n");
      }
    }
  }

  printf("You have run out of money. Game over.\n");

  return 0;
}