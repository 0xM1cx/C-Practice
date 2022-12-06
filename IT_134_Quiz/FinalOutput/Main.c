#include <stdio.h>
#include <time.h>
#include <stdlib.h>

    int rollCounter = 1;



void play(){
    srand(time(0));

    int dieOne = rand() % 6 + 1;
    int dieTwo = rand() % 6 + 1;
    int sum = dieOne + dieTwo;

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
    printf("WELCOME PLAYER");
    printf("[P]lay\n[E]xit");
    scanf("%c", &UserInput);

    if(UserInput == 'P' || UserInput == 'p'){
        play();
    }
    else if(UserInput == 'E' || UserInput == 'e'){
        exit(0);
    }else{
        printf("Invalid Input, it must be either P or E");
        sleep(3);
        main();
    }
}