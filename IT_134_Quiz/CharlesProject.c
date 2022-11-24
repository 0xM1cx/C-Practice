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

// int getCards(){

//     // Step 4
//     srand(time(0)); // Para mag babago yung random number everytime na matatawag itong getCards()
    
//     int randNums[2];
//     int randNumsSymbols[2];
//     int TotalrandNums[4];

    
//     // Getting the symbols for the card
//     for(int i = 0; i <= 1; i++){
//         TotalrandNums[i] = rand() % 3;
//     }

//     // Getting the car number
//     for(int b = 2; b<=3; b++){
//         TotalrandNums[b] = rand() % 9;
//     }
    
//     return TotalrandNums;
// }


void main(){
    // Initializing variables with their specified values
    char num[10] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', '10'};
    char shapes[4][10] = {"Hearts", "Spades", "Clubs", "Diamonds"};

    // Ask players for their names
    char playerOne[50];
    char playerTwo[50];

    // Step 1
    printf("Player 1: What is your name? ");
    scanf("%s", playerOne);

    printf("Player 2: What is your name? ");
    scanf("%s", playerTwo);

    // Step 2 and 3
    printf("Card is shuffling........");
    sleep(5);
    printf("\nCard is giving to both players");
    sleep(5);


    goto getPlayerOneCards;
    goto getPlayerTwoCards;
    
    // Generating Cards for Player 1
    getPlayerOneCards:
        srand(time(0)); // Para mag babago yung random number everytime na matatawag itong getCards()
        
        int randNums[2];
        int randNumsSymbols[2];

        
        // Getting the symbols for the card
        for(int i = 0; i <= 1; i++){
            randNumsSymbols[i] = rand() % 3;
        }

        // Getting the car number
        for(int b = 0; b<=1; b++){
            randNums[b] = rand() % 9;
        }


    // Generating Cards for Player 2
    getPlayerTwoCards:
        srand(time(0)); // Para mag babago yung random number everytime na matatawag itong getCards()
        
        int _randNums[2];
        int _randNumsSymbols[2];

        
        // Getting the symbols for the card
        for(int i = 0; i <= 1; i++){
            _randNumsSymbols[i] = rand() % 3;
        }

        // Getting the car number
        for(int b = 0; b<=1; b++){
            _randNums[b] = rand() % 9;
        }
    
 
    int playerOneSum = num[randNums[0]] + num[randNums[1]];
    int playerTwoSum = num[_randNums[0]] + num[_randNums[1]];

    
    // Displaying Cards to the USER
    system("cls");
    printf("Player %s: %d of %d and %d of %d\n", playerOne, randNums[0], randNumsSymbols[0], randNums[1], randNumsSymbols[1]);
    printf("Player %s: %d of %d and %d of %d", playerTwo, _randNums[0], _randNumsSymbols[0], _randNums[3], _randNumsSymbols[1]);



} 