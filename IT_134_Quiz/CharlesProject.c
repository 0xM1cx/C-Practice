#include <stdio.h> // Para sa printf() tapos scanf()
#include <time.h> // Para sa srand(time(0))
#include <unistd.h> // Para sa sleep()
#include <windows.h> // Para sa sleep()
#include <stdlib.h> // Para sa atoi()

void findWinner(int playerOneSum, int playerTwoSum){
    if (playerOneSum > playerTwoSum){
        printf("\nPlayer 1 is the winner!!");
    }
    else if(playerTwoSum > playerOneSum){
        printf("\nPlayer 2 is the winner!!");
    }else{
        printf("\nITS A TIE!!");
    }
}

int getCards(){

    // Step 4
    srand(time(0)); // Para mag babago yung random number everytime na matatawag itong getCards()
    
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

    int playerOneSum = atoi(playerOneValues[2]) + atoi(playerOneValues[3]);
    int playerTwoSum = atoi(playerTwoValues[2]) + atoi(playerTwoValues[3]);

    // Displaying Cards to the USER
    printf("Player 1: %c of %s and %c of %s", playerOneValues[2], playerOneValues[0], playerOneValues[3], playerOneValues[1]);
    printf("Player 2: %c of %s and %c of %s", playerTwoValues[2], playerTwoValues[0], playerTwoValues[3], playerTwoValues[1]);

    findWinner(playerOneSum, playerTwoSum);

}