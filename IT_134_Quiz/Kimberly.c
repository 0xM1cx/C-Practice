
#include <stdio.h>
#include <windows.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

voide goToOffice(), goNear(), BookTwo(), BookOne(char *playerName);


void goToOffice(){
    
}

void goNear(){

}


void BookTwo(){

}


void BookOne(char *playerName){
    int userInput;
    char username[20] = "Peace";
    printf("You are a bookworm, always reading books day and night. From firctionn to facts, horror to comedy.\nWhen someone asks you what book they should read, you already know the answer not by random but by examining\nthe kind of person they are and the type of book they would like.\n\n\n");

    sleep(2);
    printf("One day you go home, tired, hungry and itching to read the new book you just bought the other day entitled\n\"The Reader's Adventure to the Unknown\". At 9:00 pm you sit down in you bed and start reading the book. After 2 hours\nyou start to feel doozy and slowly fall asleep with the book beside you bed.\n\n\n");

    sleep(2);
    printf("You wake up in an unfamiliar forest. Unable to recall what happened after you dozed off. You hear something, a\nrattling sound near the bushes to you left. Then someone came out, a girl with a bow and arrow. Telling you to duck and\ncover as she was about to hit the boar behind you.\n\n\n");
    sleep(2);
    printf("*You duck out of the way*\n\n\n");
    sleep(2);
    printf("*She hits the boar behind you*\n\n\n");
    sleep(2);
    printf("After she hits the boar she says sorry to you, knowing that you've been put into danger. She asks\n\n\n");
    sleep(2);
    printf("Stranger: What is your name?\n\n");
    choiceOne:
        printf("YOUR CHOICES:\n1. Tell you name\n2. Don't tell her\n");
        scanf("%d", &userInput);
    if(userInput == 1){
        strcpy(username, playerName);
        printf("...I'm %s", username);
    }
    else if(userInput == 2){
        printf("YOU: uhm...I'd rather not say\n\n");
        printf("Stranger: Ok...Yeah. I understand anonymity is important; especially when you're in an unknown place.\nFrom now on I will call you \"Peace\" as a symbol of our peaceful friendship");
    }else{
        goto choiceOne;
    }


    printf("Sorry about that, I'm Crystal, a professional adventurer from the town to the north named Negus.\nIf it's ok to ask, what were you doing here in the forest.\n\n");
    printf("YOU: I don't recall. I just woke up here\n\n");
    printf("CRYSTAL: Do you recall something, even just a little? Home? Family or Friends?\n\n");
    printf("YOU: No...The last thing I remember was reading a book before dozing off\n\n\n");
    printf("CRYSTAL: This is problematic...Ok, come with me, let's go to Chiba, its a town nearby. I know a doctor there.\nHe might be able to help you, especially after the situation you've just experienced. After that \nI'll treat you to dinner as an apology for earlier\n\n\n");
    printf("YOU: OK\n\n\n\n");
    sleep(3);
    printf("*You and Crystal Walk to Chiba*");
    sleep(4);

    printf("After arriving and going into the doctor's office you see something in the corner of you eye. A sort of flash\n\n");

    choiceTwo:
        printf("YOUR CHOICE:\n 1. Go Near it\n2. Go Directly to the Doctors office\n\n");
        scanf("%d", &userInput);
    if(userInput == 1){
        goNear();
    }
    else if(userInput == 2){
        goToOffice();
    }else{
        goto choiceTwo;
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