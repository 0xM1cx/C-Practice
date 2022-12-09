#include <stdio.h>
#include <windows.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void goToOffice(), goNear(), BookTwo(), BookOne(char *playerName);



void goToOffice(char *username){
    printf("You go near it and saw a brown and worn out grimoire with a\nclover logo. As your hand gets closer the shine from the grimoire\ngets brighter.")
    printf("\n*someone grabs your hand before you could touch it*");

    printf("DOCTOR: Who are you?\n\n");
    printf("YOU: Sorry, I wasn't gonna steal it. I just saw it glowing and it got me curious\n\n");
    printf("*Crystal intervenes and says sorry to the professor*\n\n");
    printf("CRYSTAL: Hey Doc, sorry about that. This is %s. I've brought her here\nbecause I thought you could help her.\n\n", username);
    printf("DOCTOR: OK...Um sorry about that. I was just worried that a person was\ntrying to steal my stuff...\n That grimoire glowed when your hand came near it. Did you feel anything?\n\n");
    printf("YOU: Yes, I felt like something was surging within me. Like it was reaching my soul\n\n");

    printf("DOCTOR: Grimoire is a special kind of book, in which they only choose a handful\nof people to be their master. A person who\n holds a grimoire can learn to read and use the spells stored within it.\nMaybe it's best to give it to you. As it seems that the grimoire determined you to be\nworthy of being a reader of its spells.\n\n");
    printf("DOCTOR: So Crystal what seems to be the problem. As I guessed you didn’t come here without a good reason.\n\n");
    printf("CRYSTAL: You see…\n\n*CRYSTAL tells the whole story to the Doctor*\n\n");
    printf("DOCTOR: OK, I understand. Let’s go to my office.\n\n");
    
    BookTwo();

}

void goNear(char *username){
    printf("*Both of you enter the Doctors office.*\n\n");
    printf("DOCTOR: Greetings Crystal. Have you been well?\n\nCRYSTAL: Yes Doc, and you?\n\nDOCTOR: Splendid. Who is this?\n\n");
    printf("CRYSTAL: This is my friend %s\n\n", username);
    printf("YOU: Hello.\n\nDOCTOR: Pleasure to meet you %s. How can I assist you?", username);

    printf("CRYSTAL: Well...\n\n");

    printf("*Crystal Proceeds to tell the whole story to the doctor*\n\n");

    printf("DOCTOR: OK. I understand.\n\n");

    BookTwo();
}


void BookTwo(){
    printf("DOCTOR: What genre of books do you like?");
    printf("YOU: I like sci-fi stories, something like cyberpunk");
    printf("DOCTOR: Why sci-fi?");
    printf("YOU: Because I like technology, programming, network engineering, etc.\n Ever since I was in elementary I dabled with tech with the support of my father who\n worked in IT");
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
        goNear(username);
    }
    else if(userInput == 2){
        goToOffice(username);
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



