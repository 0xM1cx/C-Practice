#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

int generateRandomNumber(){
// This function generates a new number everytime it is called.
    srand(time(0));
    int rando = rand() %2 + 1;

    return rando;
}

int main(){

    float bank;
    float bet;
    int gesu;
    int rando;
    int ans;

    srand(time(0));
    rando = rand() % 2 + 1;

// Title & Intro
    printf("\n\n-----------------------\n\n");
    printf("\tGAMBURU\n\n");
    printf("-----------------------\n\n");
    getch();
    printf("ARE YOU FEELING LUCKY??\n\n");
    printf("-----------------------\n\n");
    getch();
// Deposit
    do {
        printf("Deposit Your Money in the GAMBURU Bank!\n");
        printf("Deposit money here: ");
        scanf("%f", &bank);
        printf("\nMoney in the Bank: %.2f\n\n", bank);
        printf("-----------------------\n\n");

        if(bank <= 0){
            printf("Insufficient Deposit! Try Again!\n\n");
            printf("-----------------------\n\n");
        }

    } while(bank <= 0);
// Main Machinery
    do {
    // Bet
        while(bank > 0){
            printf("How much money you wanna waste??\n");
            printf("Place your bet here: ");
            scanf("%f", &bet);
            printf("\n-----------------------\n\n");

            if(bet > bank){
                printf("Bet Exceeds Current Balance! Try Again!\n\n");
                printf("-----------------------\n\n");
            } else {
                break;
            }
        }

        do {
            printf("HEADS OR TAILS?[1 = HEADS, 2 = TAILS]");
            printf("\nEnter your guess here: ");
            scanf("%d", &gesu);


            if(gesu < 1 || gesu > 2){
                printf("\nINVALID INPUT!\n");
            }

            printf("\n-----------------------\n\n");
        } while (gesu < 1 || gesu > 2);

        // Heads or Tails
        if(gesu == rando){

            printf("CONGRATULATIONS!!! YOUR GUESS IS CORRECT!!!\n\n");
            bank = bank + bet;
            printf("-----------------------\n\n");
            printf("Money in the Bank: %.2f\n\n", bank);
            printf("-----------------------\n\n");
            


        } else {
            printf("OOPS !!! SORRY!!! YOUR GUESS IS WRONG!!!\n");

            if(rando == 1){
                printf("The Correct Answer is HEADS!\n\n");
            } else if(rando == 2){
                printf("The Correct Answer is TAILS!\n\n");
            }
            bank = bank - bet;
            printf("-----------------------\n\n");
            printf("Money in the Bank: %.2f\n\n", bank);
            printf("-----------------------\n\n");

            
        }

        rando = generateRandomNumber(); // nag assign bago na number base sa generateRandomNumber() function above.
    // Play Again?
        do {
            printf("Wanna Waste More Money??[1 = Yes, 0 = No]\n");
            printf("Answer here: ");
            scanf("%d", &ans);

            if(ans < 0 || ans > 1){
                printf("\nINVALID INPUT!\n");
            }
            printf("\n-----------------------\n\n");
        } while (ans < 0 || ans > 1);
    } while(ans == 1);

        printf("Thank You For Playing GAMBURU!\nPlease Come Again Soon & Waste More Money!\n\n");
        printf("-----------------------\n\n");

    return 0;
}
