#include <stdio.h> // For the scanf and printf functions
#include <time.h> // for the time() function for generating a new random number everytime the rand() is called
#include <stdlib.h> 
#include <unistd.h> // for the sleep(), compatability for linux
#include <windows.h> // for the sleep(), compatability for windows

// Declaring the functions to be used
int getRanNums(); 
void succedingRolls(int userBet, int valToWin);
void play(int userBet);
void bet();

// Declaring and initializing the global variables to be used
int currentCapital = 1000;
int RollsArr[100][100];
int currentRoll = 0;



// Main function where the program will first start
void main(){
    srand(time(0));
    char UserInput; // This is used to get the user input

    currentRoll = 0; // this is used for the number of the row used in the 2d array


    printf("WELCOME PLAYER\n\n");
    printf("Current Capital: %d\n\n\n", currentCapital); // Displaying the current capital to the user
    printf("[P]lay\n[E]xit\n\nINPUT: ");
    scanf(" %c", &UserInput);

    if(UserInput == 'P' || UserInput == 'p'){
        bet();
    }
    else if(UserInput == 'E' || UserInput == 'e'){
        exit(0);
    }
    else{
        printf("Invalid Input, it must be either P or E");
        sleep(3);
        main();
    }
}


int getRanNums(){

    int dieOne = rand() % 6 + 1; // Invokes a random number for 
    int dieTwo = rand() % 6 + 1;
    int sum = dieOne + dieTwo;
    
    RollsArr[currentRoll][0] = dieOne;
    RollsArr[currentRoll][1] = dieTwo;
    RollsArr[currentRoll][2] = sum;
    return sum;
}


void succedingRolls(int userBet, int valToWin){

    srand(time(0));
    int valueToWin = valToWin;
    int isDone = 1;
    while(isDone){

        int randNum = getRanNums();
        printf("Roll %d\n\t", currentRoll+1);
        printf("D1: %d\n\t", RollsArr[currentRoll][0]);
        printf("D2: %d\n\t", RollsArr[currentRoll][1]);
        printf("T: %d\n", RollsArr[currentRoll][2]);

        if(randNum == valueToWin){
            printf("Winner!!\n\n");
            currentCapital += userBet;
            main();
            isDone = 0;
        }else if (randNum == 7)
        {
            printf("You Lost!!\n\n");
            currentCapital -= userBet;
            main();
            isDone = 0;
        }
        currentRoll++;
        for(int i = 0; i<= 4; i++){
            printf(".");
            sleep(1);
        }
        printf("\n");
    }
}


void play(int userBet){

    
    int randNum = getRanNums();
    printf("Roll 1\n\t");
    printf("D1: %d\n\t", RollsArr[currentRoll][0]);
    printf("D2: %d\n\t", RollsArr[currentRoll][1]);
    printf("T: %d\n", RollsArr[currentRoll][2]);
    
    currentRoll++;
    
    if (randNum == 7)
    {
        printf("We have a winner");
        currentCapital += userBet;
        main();
    }
    else if(randNum == 11 || randNum == 2){
        printf("You have lost");
        currentCapital -= userBet;
        main();
    }else{
        for(int i = 0; i<= 4; i++){
            printf(".");
            sleep(1);
        }
        printf("\n");
        succedingRolls(userBet, randNum);
    }           
}

void bet(){
    int userBet;

    printf("\nYOUR BET: ");
    scanf("%d", &userBet);
    if(userBet <= 0 || userBet >currentCapital){
        printf("Invalid Bet");
        sleep(3);
        bet();
    }

    play(userBet);
}
