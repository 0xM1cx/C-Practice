#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int rollCounter = 1;

void play(){
    srand(time(0));

    int dieOne = rand() % 6 + 1; // Invokes a random number for 
    int dieTwo = rand() % 6 + 1;
    int sum = dieOne + dieTwo;



    // Set input for the user to be the next random number
    // isWinner will be the flag 
    int isWinner = 0;
    for(;isWinner != 1; rollCounter++){
        if(rollCounter == 1){
            if (sum == 7)
            {
                
            }
            
        }
    }
}



void main(){
    char UserInput;
    printf("WELCOME PLAYER\n\n");
    printf("[P]lay\n[E]xit\n");
    scanf(" %c", &UserInput);

    if(UserInput == 'P' || UserInput == 'p'){
        play();
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