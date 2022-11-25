#include <stdio.h>
#include <windows.h>
#include <unistd.h>
#include <stdlib.h>

void BookTwo(){

}


void BookOne(){

}


void main(){

    // Ask the player for his/her name
    char playerName[20];
    printf("PLAYER NAME: ");
    scanf("%s", playerName);
    printf("Loading Game..");
    for (int i = 0; i < 3; i++)
    {
        sleep(1);
        printf(".");
    }
    sleep(2);
    system("cls");
    printf("=========================\n");
    printf("WELCOME %s \t", playerName);
    printf("\n=========================\n");
}