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

/*Lucky 9
Ung array is range from{ 'A', 2-10)
Tapos {Hearts, Spades, Clover, Diamond}


1. Mag aask si program ng name ng dalawag player, tpaos un yung magiging name ni Player 1 and Player 2. (Ex. Player Josh and Player Earl)

2. Next, may lalabas na "Card is shuffling........." (delay for 10s

3. "Card is giving to both players" 

4. Player 1 card "9 of hearts and 7 of spades" tapos kay player 2 din ganon

5. (5s bago lumabas to) Player Josh, you want another card? If yes, magbibigay ng card pero naka "* of ****" muna, if No proceed na kay player 2.  Pagdating kay player 2,ganon din mag aask din mun,a if Yes print "Your card is ****" ganyan. 

7. Lalabas ung total cards, kasama ung isang extra na card na inask ni program 

8. After non, lalabas na ung result ganto
"Player 1 total card: 1 of hearts, 4 of spades and 3 of  diamonds with a total acore of 8" same kay player 2 ganyan din.

9. If more than 9 ung score, minus 10 dapat, so kapag 10 ung total, magiging 0 ung score, kapag 11 naman, magiging 1 ung score 

10. (3s bago lumabas to) Player 1 is the winner.*/


void main(){
    // Initializing variables with their specified values
    char num[10] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '10'};
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

    srand(time(0));
    goto getPlayerOneCards;
    goto getPlayerTwoCards;
    
    // Generating Cards for Player 1
        int randNums[2];
        int randNumsSymbols[2];
    getPlayerOneCards:
         // Para mag babago yung random number everytime na matatawag itong getCards()
        

        
        // Getting the symbols for the card
        for(int i = 0; i <= 1; i++){
            randNumsSymbols[i] = rand() % 4;
        }

        // Getting the car number
        for(int b = 0; b<=1; b++){
            randNums[b] = rand() % 9;
        }


    // Generating Cards for Player 2
        int _randNums[2];
        int _randNumsSymbols[2];
    getPlayerTwoCards:
     // Para mag babago yung random number everytime na matatawag itong getCards()
        

        
        // Getting the symbols for the card
        for(int i = 0; i <= 1; i++){
            _randNumsSymbols[i] = rand() % 4;
        }

        // Getting the car number
        for(int b = 0; b<=1; b++){
            _randNums[b] = rand() % 9;
        }
    
   
    int playerOneSum = (num[randNums[0]] - '0') + (num[randNums[1]] - '0');
    int playerTwoSum = (num[_randNums[0]] - '0') + (num[_randNums[1]] - '0');

    printf("\n%d", playerOneSum);
    printf("\n%d\n", playerTwoSum);

    
    // Displaying Cards to the USER
    // The the purpose of the conditions is to see if it is 1 because 1 in lucky 9 is A, so it will replace  1 with A.
    if(randNums[0] == '1'){
        randNums[0] = 'A';
        printf("\nPlayer %s: %c of %s and %c of %s\n", playerTwo, num[_randNums[0]], shapes[_randNumsSymbols[0]], num[_randNums[1]], shapes[_randNumsSymbols[1]]);
        printf("Player %s: %c of %s and %c of %s\n", playerOne, num[randNums[0]], shapes[randNumsSymbols[0]], num[randNums[1]], shapes[randNumsSymbols[1]]);
    }else if(randNums[1] == '1'){
        randNums[1] = 'A'; 
        printf("\nPlayer %s: %c of %s and %c of %s\n", playerTwo, num[_randNums[0]], shapes[_randNumsSymbols[0]], num[_randNums[1]], shapes[_randNumsSymbols[1]]);
        printf("Player %s: %c of %s and %c of %s\n", playerOne, num[randNums[0]], shapes[randNumsSymbols[0]], num[randNums[1]], shapes[randNumsSymbols[1]]);
    }else{
        printf("\nPlayer %s: %c of %s and %c of %s\n", playerTwo, num[_randNums[0]], shapes[_randNumsSymbols[0]], num[_randNums[1]], shapes[_randNumsSymbols[1]]);
        printf("Player %s: %c of %s and %c of %s\n", playerOne, num[randNums[0]], shapes[randNumsSymbols[0]], num[randNums[1]], shapes[randNumsSymbols[1]]);
    }

    findWinner(playerOneSum, playerTwoSum);

} 