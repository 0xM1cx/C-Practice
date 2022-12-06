#include <stdio.h>
#include <windows.h>
#include <unistd.h>
#include <stdlib.h>

void BookOneChoiceOne(playerName){
    printf("...I'm %s", playerName);
}

void BookOneChoiceTwo(){

}



void BookTwo(){

}


void BookOne(playerName){
    int userInput;
    char playername[20];
    printf("You are a bookworm, always reading books day and night. From firctionn to facts, horror to comedy.\n
    When someone asks you what book they should read, you already know the answer not by random but by examining\n
    the kind of person they are and the type of book they would like.\n");

    sleep(2);
    printf("One day you go home, tired, hungry and itching to read the new book you just bought the other day entitled\n
    \"The Reader's Adventure to the Unknown\". At 9:00 pm you sit down in you bed and start reading the book. After 2 hours\n
    you start to feel doozy and slowly fall asleep with the book beside you bed.\n");

    printf("You wake up in an unfamiliar forest. Unable to recall what happened after you dozed off. You hear something, a\n
    rattling sound near the bushes to you left. Then someone came out, a girl with a bow and arrow. Telling you to duck and\n
    cover as she was about to hit the boar behind you.\n");

    printf("*You duck out of the way*\n");
    printf("*She hits the boar behind you*");

    printf("After she hits the boar she says sorry to you, knowing that you've been put into danger. She asks\n");

    printf("CRYSTAL: What is your name?");
    choiceOne:
        printf("YOU CHOICES:\n
        1. Tell you name\n
        2. Don't tell her\n");
        scanf("%d", %userInput);
    if(userInput == 1){
        BookOneChoiceOne(playerName);
        playername = playerName;
    }
    else if(userInput == 2){
        BookOneChoiceTwo();
    }else{

    }
    
}


void main(){

    // Initializing gameplay system variables
    int playerLife = 10;
    char grimoiresOfChoice[2][20] = {"Burakkugurimoa", "Akuagurimoa"};
    char playerGrimoire[20];
    
    

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
    printf("\n=========================\n\n\n");

    BookOne(playerName);

}