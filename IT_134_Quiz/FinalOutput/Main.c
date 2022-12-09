#include <stdio.h> // For the scanf and printf functions
#include <time.h> // for the time() function for generating a new random number everytime the rand() is called
#include <stdlib.h> 
#include <unistd.h> // for the sleep(), compatability for linux
#include <windows.h> // for the sleep(), compatability for windows

#define size 100

// Declaring the functions to be used
int getRanNums(); 
void succedingRolls(int userBet, int valToWin), play(int userBet), bet(), playAgain(), displayInfo(), rules();

// Declaring and initializing the global variables to be used
int currentCapital = 1000;
int RollsArr[size][size];
int currentRoll = 0;



// Main function where the program will first start
void main(){
    
    system("cls");

    if (currentCapital == 0)
    {
        char usrInput;
        printf("No More Money.\n\n\nThank You For Playing");
        printf("\n\nPress Any Key to Continue");
        scanf(" %c", &usrInput);
        exit(0);
    }
    
    srand(time(0));
    char UserInput; // This is used to get the user input

    printf("\033[0;37m");
    printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",95,95,95,220, 223, 223, 223, 220,220,220,220,220,220,220,223,223,223,220,95,95,95);
    printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 196,196,196, 219, 178,178, 178,178,178,178,178,178,178,178,178,178,178,219,196,196,196);
    printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 196,196,196, 196,219,178,178,219,178,178,178,178,178,219,178,178,219,196,196,196);
    printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 196,220,220,196,196,219,178,178,178,223,219,223,178,178,178,219,196,196,220,220,196);
    printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 219,178,178,219,196,223,220,178,178,178,178,178,178,178,220,223,196,219,178,178,219);
    printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,219);
    printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219,178,178, 203,196,203, 201,187,203,196,201,187,201,187,201,203,187,201,187,178,219);
    printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219,178,178,  186,186,186,  204,196, 186,196,186,196,186,186,186,186,186,204,196,178,219);
    printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219,178,178, 200,202,188,  200,188, 200,188, 200,188, 200,188,202,196,202, 200,188,178,219);
    printf("\t\t\t %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n",219,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,219);
    printf("\033[0;32m");

    currentRoll = 0; // this is used for the number of the row used in the 2d array
    // printf("\033[0;37m");
    // printf("=========================\n\n");
    // printf("\033[0;34m");
    // printf("WELCOME TO ROLL OR DIE\n\n");
    // printf("\033[0;37m");
    // printf("=========================\n\n\n");

    
    displayInfo();

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
        sleep(2);
        main();
    }
}


void playAgain(){
    char userInput;
    
    printf("Do you want to play again? Y or N\nINPUT: ");
    scanf(" %c", &userInput);

    if(userInput == 'Y' || userInput == 'y'){
        bet();
    }
    else if(userInput == 'N' || userInput == 'n'){
        system("cls");
        printf("\033[0;37m");
        printf("=========================\n\n");
        printf("\033[0;34m");
        printf("Thank You For \033[0;37m Playing!!\n\n");
        printf("\033[0;37m");
        printf("=========================\n\n\n\n\n");
        displayInfo();
        sleep(2);
        exit(0);
    }else{
        printf("Wrong Input!!!");
        sleep(2);
        playAgain();  
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
        printf("T: %d\n\n", RollsArr[currentRoll][2]);

        if(randNum == valueToWin){
            printf("Winner!!\n\n");
            currentCapital += userBet;
            playAgain();
            isDone = 0;
        }else if (randNum == 7)
        {
            printf("You Lost!!\n\n");
            currentCapital -= userBet;
            playAgain();
            isDone = 0;
        }
        currentRoll++;

        printf("\n\nRolling Dice and Getting sum  ");
        for (int i = 0; i<=0; i++) {
            sleep(1);
            printf("\b\\");
            
            sleep(1);
            printf("\b|");
        
            sleep(1);
            printf("\b/");
        
            sleep(1);
            printf("\b--");
            sleep(1);
    }
        printf("\n");
    }
}


void play(int userBet){

    
    int randNum = getRanNums();

    printf("\n\nRolling Dice and Getting sum  ");
    for (int i = 0; i<=0; i++) {
        sleep(1);
        printf("\b\\");
        
        sleep(1);
        printf("\b|");
       
        sleep(1);
        printf("\b/");
       
        sleep(1);
        printf("\b--");
        sleep(1);
    }
    

    printf("\n\nRoll 1\n\t");
    printf("D1: %d\n\t", RollsArr[currentRoll][0]);
    printf("D2: %d\n\t", RollsArr[currentRoll][1]);
    printf("T: %d\n", RollsArr[currentRoll][2]);
    
    currentRoll++;
    
    if (randNum == 7)
    {
        printf("We have a winner\n\n");
        currentCapital += userBet;
        playAgain();
    }
    else if(randNum == 11 || randNum == 2){
        printf("You have lost\n\n");
        currentCapital -= userBet;
        playAgain();
    }else{
        printf("\n\nRolling Dice and Getting sum  ");
        for (int i = 0; i<=0; i++) {
            sleep(1);
            printf("\b\\");
            
            sleep(1);
            printf("\b|");
        
            sleep(1);
            printf("\b/");
        
            sleep(1);
            printf("\b--");
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

void displayInfo(){
    printf("DEVELOPERS:\n\t");
    printf("Shawn Michael Sudaria\t @shun_m1cx\t Github: https://github.com/0xM1cx\n\t");
    printf("Jade Hart Lee\n\t");
    printf("Renz Ivan Monteza\n\n");
}


void rules(){
    system("cls");
    printf("In the 1st roll if the sum of the 2 randomly generated numbers is 7 then you will win.\nBut if the sum is 11 or 2 then you will lose. However, if the sum is neither of the\naforementioned numbers then it will move to succeeding rolls. In the 2nd rolls and onwards\nthe rules will be different, you will only win if the sum of the newly randomly generated num\nbers is equal to the sum of the first roll and you will lose if the sum is equal to 7.");

}
