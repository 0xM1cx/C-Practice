#include <stdio.h> // For the scanf and printf functions
#include <time.h> // for the time() function for generating a new random number everytime the rand() is called
#include <stdlib.h> 
#include <unistd.h> // for the sleep(), compatability for linux
#include <windows.h> // for the sleep(), compatability for windows

/*
DEVELOPERS:
+ @shun_m1cx | Shawn Michael Sudaria
+ @renz_mont | Renz Ivan Monteza
+ @jadehartlee | Jade Hart Lee
*/


#define size 100


// Declaring the functions to be used
int getRanNums(); 
void succedingRolls(int userBet, int valToWin), play(int userBet), bet(), playAgain(), displayInfo(), rules(), loadingAnimation(), displayBanner();



// Declaring and initializing the global variables to be used
int currentCapital = 1000;
int RollsArr[size][size];
int currentRoll = 0;



// Main function where the program will first start
void main(){
    system("cls");
    srand(time(0));
    char UserInput; // This is used to get the user input

    displayBanner();
    printf("\033[0;32m");


    displayInfo();

    
    printf("[P]lay\n[E]xit\n[R]ules\n\nINPUT: ");
    scanf(" %c", &UserInput);

    if(UserInput == 'P' || UserInput == 'p'){
        bet();
    }
    else if(UserInput == 'E' || UserInput == 'e'){
        exit(0);
    }
    else if(UserInput == 'R' || UserInput == 'r'){
        rules();
    }else{
        printf("Invalid Input, it must be either P or E");
        sleep(2);
        main();
    }
}


void displayBanner(){
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
    printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n",219,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,219);
}

// The Animated Loading Screen.
void loadingAnimation(){
    for (int i = 0; i<=5; i++) {
        Sleep(90);
        printf("\b\\");
        
        Sleep(90);
        printf("\b|");
    
        Sleep(90);
        printf("\b/");
    
        Sleep(90);
        printf("\b-");
        Sleep(90);
    }
    printf("\b ");
}

void playAgain(){
    char userInput;
    
    printf("\n\n\nDo you want to play again? Y or N\nINPUT: ");
    scanf(" %c", &userInput);

    if(userInput == 'Y' || userInput == 'y'){
        bet();
    }
    else if(userInput == 'N' || userInput == 'n'){
        system("cls");
        displayBanner();
        printf("\033[0;37m");
        printf("\t\t\t=========================\n\n");
        printf("\033[0;34m");
        printf("\033[0;32m \t\t\tThank You For \033[0;37m Playing!!\n\n");
        printf("\033[0;37m");
        printf("\t\t\t=========================\n\n\n\n\n");
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

    int dieOne = rand() % 6 + 1; // Invokes a random number for die 1
    int dieTwo = rand() % 6 + 1;
    int sum = dieOne + dieTwo;
    
    RollsArr[currentRoll][0] = dieOne;
    RollsArr[currentRoll][1] = dieTwo;
    RollsArr[currentRoll][2] = sum;
    return sum;
}


void succedingRolls(int userBet, int valToWin){

    srand(time(0));
    int _valueToWin = valToWin;
    int isDone = 1;

    while(isDone){

        int randNum = getRanNums();
        printf("\n\nRolling Dice and Getting sum  ");
        loadingAnimation();
        printf("\n");
        
        printf("Roll %d\n\t", currentRoll+1);
        printf("D1: %d\n\t", RollsArr[currentRoll][0]);
        printf("D2: %d\n\t", RollsArr[currentRoll][1]);
        printf("T: %d\n\n", RollsArr[currentRoll][2]);

        if(randNum == _valueToWin){
            printf("\033[0;37m");
            printf("\n\n\nWinner!!\n\n");
            currentCapital += userBet;
            printf("Current Capital: %d\n\n\n", currentCapital);
            printf("\033[0;32m");
            loadingAnimation();
            playAgain();
            isDone = 0;
        }else if (randNum == 7)
        {
            printf("\033[0;37m");
            printf("\n\n\nYou Lost!!\n\n");
            currentCapital -= userBet;
            printf("Current Capital: %d\n\n\n", currentCapital);
            printf("\033[0;32m");
            loadingAnimation();
            playAgain();
            isDone = 0;
        }else{
            _valueToWin = randNum;
            currentRoll++;
        }
    }
}


void play(int userBet){
    int randNum = getRanNums();

    currentRoll = 0; // this is used for the number of the row used in the 2d array

    printf("\n\nRolling Dice and Getting sum  ");
    loadingAnimation();
    

    printf("\n\nRoll 1\n\t");
    printf("D1: %d\n\t", RollsArr[currentRoll][0]);
    printf("D2: %d\n\t", RollsArr[currentRoll][1]);
    printf("T: %d\n", RollsArr[currentRoll][2]);
    
    currentRoll++;
    
    if (randNum == 7)
    {   
        printf("\033[0;37m");
        printf("\n\n\nWe have a winner_\n\n");
        currentCapital += userBet;
        printf("Current Capital: %d\n\n\n", currentCapital);
        printf("\033[0;32m");
        loadingAnimation();
        playAgain();
    }
    else if(randNum == 11 || randNum == 2){
        printf("\033[0;37m");
        printf("\n\n\nYou have lost\n\n");
        currentCapital -= userBet;
        printf("Current Capital: %d\n\n\n", currentCapital);
        printf("\033[0;32m");
        loadingAnimation();
        playAgain();
        
    }else{
        succedingRolls(userBet, randNum);
    }           
}

void bet(){
    int userBet;
    
    system("cls");

    displayBanner();
    printf("\033[0;32m");

    if (currentCapital == 0)
    {
        system("cls");
        printf("\033[0;37m");
        printf("\t\t\t**    **                    **                               \n");
        printf("\t\t\t//**  **                    /**                               \n");
        printf("\t\t\t //****    ******  **   **  /**        ******   ******  *****\n"); 
        printf("\t\t\t  //**    **////**/**  /**  /**       **////** **////  **///**\n");
        printf("\t\t\t   /**   /**   /**/**  /**  /**      /**   /**//***** /*******\n");
        printf("\t\t\t   /**   /**   /**/**  /**  /**      /**   /** /////**/**////\n"); 
        printf("\t\t\t   /**   //****** //******  /********//******  ****** //******\n");
        printf("\t\t\t   //     //////   //////   ////////  //////  //////   //////\n");
        printf("\033[0;32m");
        char usrInput;
        printf("\n\nInsufficient Balance.\n\n\nThank You For Playing");
        printf("\n\nPress Any E to Exit ");
        scanf(" %c", &usrInput);
        loadingAnimation();
        exit(0);
    }

    printf("Current Capital: %d\n\n\n", currentCapital); // Displaying the current capital to the user
    printf("\nYOUR BET: ");
    scanf("%d", &userBet);

    if(userBet <= 0 || userBet > currentCapital){
        printf("Invalid Bet");
        loadingAnimation();
        bet();
    }
    play(userBet);
}

void displayInfo(){
    printf("\t\t\tDEVELOPERS:\n\t");
    printf("\t\t\tShawn Michael Sudaria\t @shun_m1cx\t Github: https://github.com/0xM1cx\n\t");
    printf("\t\t\tJade Hart Lee\t\t @jadehartlee\n\t");
    printf("\t\t\tRenz Ivan Monteza\t @renz_mont\n\n");
}


void rules(){
    system("cls");      
    printf("\t\t\t==============================================\n\n");                              
    printf("\t\t\t    *******            **                \n");
    printf("\t\t\t    /**////**          /**                \n");
    printf("\t\t\t    /**   /**  **   ** /**   *****   ******\n");
    printf("\t\t\t    /*******  /**  /** /**  **///** **////\n"); 
    printf("\t\t\t    /**///**  /**  /** /** /*******//***** \n");
    printf("\t\t\t    /**  //** /**  /** /** /**////  /////**\n");
    printf("\t\t\t    /**   //**//****** *** //****** ****** \n");
    printf("\t\t\t    //     //  //////  ///  ////// //////\n\n\n");  
    printf("\t\t\t==============================================\n\n\n");
    printf("\t\t\tIn the 1st roll if the sum of the 2 randomly generated numbers is 7 then you will win.\nBut if the sum is 11 or 2 then you will lose. However, if the sum is neither of the aforementioned\nnumbers then it will move to succeeding rolls. In the 2nd rolls and onwards the rules will be different,\nyou will only win if the sum of the newly randomly generated numbers is equal to the sum of the first roll\nand you will lose if the sum is equal to 7.\n\n");

}
