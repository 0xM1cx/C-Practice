#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int getRanNums();
void succedingRolls(int userBet, int valToWin);
void play(int userBet);
void bet();


int currentCapital = 1000;
int RollsArr[100][100];
int currentRoll = 0;




void main(){
    char UserInput;

    currentRoll = 0;


    printf("WELCOME PLAYER\n\n");
    printf("[P]lay\n[E]xit\n");
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
    srand(time(0));

    int dieOne = rand() % 6 + 1; // Invokes a random number for 
    int dieTwo = rand() % 6 + 1;
    int sum = dieOne + dieTwo;
    
    RollsArr[currentRoll][0] = dieOne;
    RollsArr[currentRoll][1] = dieTwo;
    RollsArr[currentRoll][2] = sum;
    return sum;
}


void succedingRolls(int userBet, int valToWin){

    int randNum = getRanNums();
    int valueToWin = valToWin;
    int isDone = 1;

    printf("Roll %d\n\t", currentRoll+1);
    printf("D1: %d\n\t", RollsArr[currentRoll][0]);
    printf("D2: %d\n\t", RollsArr[currentRoll][1]);
    printf("T: %d\n", RollsArr[currentRoll][2]);

    while(isDone){
        if(randNum == valueToWin){
            printf("Winner!!");
            currentCapital += userBet;
            main();
            isDone = 0;
        }else if (randNum == 7)
        {
            printf("You Lost!!");
            currentCapital -= userBet;
            main();
            isDone = 0;
        }
        currentRoll++;
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
