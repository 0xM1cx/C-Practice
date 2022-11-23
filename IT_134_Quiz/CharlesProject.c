#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <windows.h>


int getCards(){
    // Step 4
    srand(time(0));
    
    int randNums[2];
    int randNumsSymbols[2];
    int TotalrandNums[4];

    
    // Getting the symbols for the card
    for(int i = 0; i <= 1; i++){
        TotalrandNums[i] = rand() % 3;
    }

    // Getting the car number
    for(int b = 2; b<=3; b++){
        TotalrandNums[b] = rand() % 9;
    }
    
    return TotalrandNums;
}


void main(){
    // Initializing variables with their specified values
    char num[10] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', '10'};
    char shapes[4][10] = {"Hearts", "Spades", "Clubs", "Diamonds"};

    // Ask players for their names
    char playerOne[50];
    char playerTwo[50];

    // Step 1
    printf("Player 1; What is your name? ");
    scanf("%s", playerOne);

    printf("Player 2; What is your name? ");
    scanf("%s", playerTwo);

    // Step 2 and 3
    printf("Car is shuffling........");
    sleep(5);
    printf("Card is giving to both players");
    sleep(5);

    int playerOneValues = getCards();
    int playerTwoValues = getCards();

    int playerOneSum = playerOneValues[2] + playerOneValues()[3];
    int playerTwoSum = playerTwoValues()[2] + playerTwoValues()[3];

    // Displaying Cards to the USER
    printf("Player 1: %c of %s and %c")



}