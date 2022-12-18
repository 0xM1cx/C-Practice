#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>

int roll() {
    return (rand() % 6) + 1;
}

void play();

void gameProper(int capital, int bet, int rollNo, int firstRoll) {
    char yn;
    int die1 = roll();
    int die2 = roll();
    
    printf("\n\n\t\tGAME PROPER\n\n");
    printf("ROLL %d\n", rollNo);
    printf("\tDie 1: %d\n", die1);
    printf("\tDie 2: %d\n", die2);
    
    if(rollNo == 1) {
		if(die1 + die2 == 7) {
	        printf("\n\tCongratulations you win the game!\n\n");
	    } else if(die1 + die2 == 11 || die1 + die2 == 2) {
	        capital -= bet;
	        printf("\n\tLOSE: %d\n", bet);
	        printf("\tBET: %d\n\n", bet);
		} else {
			gameProper(capital, bet, rollNo + 1, firstRoll);
		}
	} else {
		if(die1 + die2 == firstRoll) {
	        printf("\n\n\tCongratulations you win the game!\n\n");
		} else if(die1 + die2 == 7) {
	        capital -= bet;
	        printf("\n\tLOSE: %d\n", bet);
	        printf("\tBET: %d\n\n", bet);
		} else {
			gameProper(capital, bet, rollNo + 1, firstRoll);
		}
	}
	
    printf("Play Again? Y/N: ");
    fflush(stdin);
    yn = getc(stdin);
	
	if(yn == 'Y') {
		play();
	}
   
}

void play() {
    int capital, bet;
    
    printf("Capital: ");
    scanf("%i", &capital);
    
    printf("Bet: ");
    scanf("%i", &bet);
    
    gameProper(capital, bet, 1, 7);
}

int main()
{
    char choice;
    srand(time(NULL));
    
    while(1) {
        system("cls");
        printf("\t DICE\n\n");
        
        printf("\t[P]lay\n");
        printf("\t[E]xit\n\n");
        
        printf("Choice: ");
        fflush(stdin);
        choice = getc(stdin);
        
        if(choice == 'P') play();
        else if(choice == 'E') break;
        else printf("\n Invalid Input!");
    }
    
    return 0;
}