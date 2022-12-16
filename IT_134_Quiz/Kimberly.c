#include <stdio.h>
#include <windows.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define size 5

void goToOffice(), goNear(), BookTwo(), BookOne(char *playerName), loadingAnimation(), getWish(), end(), game(), BookThree(), BookTheePartTwo();
int getRandnum();
int playerGotBook = 0;
int points = 0;
char name[30];


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
    printf("\n=========================\n\n\n");
    loadingAnimation();
    BookOne(playerName);
}


void BookTheePartTwo(){
    printf("*A flash appears blinding you\n*");
    sleep(2);
    printf("*As you start to wake up, you \n*");
    sleep(2);
    printf("**");
    sleep(2);
    printf("");
    sleep(2);
}


void BookThree(){
    char userAns;
    printf("*You wake up in an empty white room*");
    sleep(2);
    printf("*A gray distorted figure appears in front of you saying*");
    sleep(2);
    printf("\"You have called the spirit of the crystal ball\n\"");
    sleep(2);
    printf("\"You wish to have the memories which you've lost in order for you to find your way home\n\"");
    sleep(2);
    printf("\"Before I give you your wish, you must solve my riddles.\n\n\"");
    sleep(2);
    
    char answers[size][30] = {"Keyboard", "Mouse", "Monitor", "Internet Explorer", "windows"};
    char riddles[size][50] = {
        "I can write without a pen, without the number 10, what am I?",
        "I have a tail and two flat ears. I move with no feet",
        "A box to anywhere. Just watch for my glare.",
        "I move slower than molasses, if you use me, you probably wear glasses.",
        "25 years old, but only turned 10"
    };

    srand(time(NULL));
    int currentRiddle = 1;
    int riddleScore = 0;
    char currentWord[100];

    for(int j = 0; j <= size; j++){
        for (int i = 0; i < 30; i++)
        {
            printf("%d. %s\n", currentRiddle, riddles[j][i]);
            printf("Your Answer: ");
            scanf(" %s", userAns);
            currentWord == riddles[j][i];
        }
        if(strcmp(currentWord, userAns) == 0){
            riddleScore++;
        }
        currentRiddle++;   
    }

    if(riddleScore >= 3){
        printf("\"You've done well. I will now grant you're wish\"");
        system("cls");
        BookTheePartTwo();

    }else{
        printf("\"You've failed to meet the required score of 3 correct answers.\n I cannot give you your wish.\"");
    }
}

void game(){
    char userAns[30];
    char wordsToGuess[8][30] = {"CPU", "GPU", "Monitor", "Programming", "Binary", "Network", "WAN", "LAN"}; 
    printf("\033[0;37m");
    for(int i = 0; i <= 7; i++){
    int randNum = getRandnum();
    switch(randNum)
    {
    case 0:
        printf("\033[0;37m");
        printf("It is where data is processed. What computer component is it\n\n");
        printf("HINT: ");
        for(int i = 1; i <= strlen(wordsToGuess[randNum]); i++){
            printf("*");
        }
        printf("\n\nYOUR ANSWER: ");
        scanf(" %s", userAns);
        if(strcmp(userAns, wordsToGuess[randNum]) == 0){
            printf("Correct\n\n");
            points++;
            
        
        }else{
            printf("Wrong\n\n");
            points--;
        }
        break;
    case 1:
        printf("\033[0;37m");
        printf("primarily used to manage and improve video and graphics performance\n\n");
        printf("HINT: ");
        for(int i = 1; i <= strlen(wordsToGuess[randNum]); i++){
            printf("*");
        }
        printf("\n\nYOUR ANSWER: ");
        scanf(" %s", userAns);
        if(strcmp(userAns, wordsToGuess[randNum]) == 0){
            printf("Correct\n\n");
            points++;
        
            
        }else{
            printf("Wrong\n\n");
            points--;
        

        }
        break;


    case 2:
        printf("\033[0;37m");
        printf("This device displays the processed data\n\n");
        printf("HINT: ");
        for(int i = 1; i <= strlen(wordsToGuess[randNum]); i++){
            printf("*");
        }
        printf("\n\nYOUR ANSWER: ");
        scanf(" %s", userAns);
        if(strcmp(userAns, wordsToGuess[randNum]) == 0){
            printf("Correct\n\n");
            points++;
        }else{
            printf("Wrong\n\n");
            points--;
           
        }
        break;
    case 3:
        printf("\033[0;37m");
        printf("It is an act of writing instructions for the computer to execute\n\n");
        printf("HINT: ");
        for(int i = 1; i <= strlen(wordsToGuess[randNum]); i++){
            printf("*");
        }
        printf("\n\nYOUR ANSWER: ");
        scanf(" %s", userAns);
        if(strcmp(userAns, wordsToGuess[randNum]) == 0){
            printf("Correct\n\n");
            points++;

            
        }else{
            printf("Wrong\n\n");
            points--;
        }
        break;
    case 4:
        printf("\033[0;37m");
        printf("A 2 base number system that computer use\n\n");
        printf("HINT: ");
        for(int i = 1; i <= strlen(wordsToGuess[randNum]); i++){
            printf("*");
        }
        printf("\n\nYOUR ANSWER: ");
        scanf(" %s", userAns);
        if(strcmp(userAns, wordsToGuess[randNum]) == 0){
            printf("Correct\n\n");
            points++;
    
            
        }else{
            printf("Wrong\n\n");
            points--;
        }
        break;
    case 5:
        printf("\033[0;37m");
        printf("It a interconnection of nodes where they can send and receive data from each other\n\n");
        printf("HINT: ");
        for(int i = 1; i <= strlen(wordsToGuess[randNum]); i++){
            printf("*");
        }
        printf("\n\nYOUR ANSWER: ");
        scanf(" %s", userAns);
        if(strcmp(userAns, wordsToGuess[randNum]) == 0){
            printf("Correct\n\n");
            points++;

        
        }else{
            printf("Wrong\n\n");
            points--;
        }
        break;
    case 6:
        printf("\033[0;37m");
        printf("It is a network topology where it is situated in a wide gelogical landscape\n\n");
        printf("HINT: ");
        for(int i = 1; i <= strlen(wordsToGuess[randNum]); i++){
            printf("*");
        }
        printf("\n\nYOUR ANSWER: ");
        scanf(" %s", userAns);
        if(strcmp(userAns, wordsToGuess[randNum]) == 0){
            printf("Correct\n\n");
            points++;
        }else{
            printf("Wrong\n\n");
            points--;    
        }
        break;
    case 7:
        printf("\033[0;37m");
        printf("It is a network toplogy which spans in a local area\n\n");
        printf("HINT: ");
        for(int i = 1; i <= strlen(wordsToGuess[randNum]); i++){
            printf("*");
        }
        printf("\n\nYOUR ANSWER: ");
        scanf(" %s", userAns);
        if(strcmp(userAns, wordsToGuess[randNum]) == 0){
            printf("Correct\n\n");
            points++;
        }else{
            printf("Wrong\n\n");
            points--;
        }
        break;
    }
}
    
    printf("\033[0;32m");
}

void end(){
    system("cls");
    printf("Thank you for playing");
    loadingAnimation();
}

void getWish(){
    printf("DOCTOR: Great you have passed the test, you can now get you wish\n\n");
    sleep(3);
    printf("*You wish to get your memories back*\n\n");
    sleep(3);
    printf("*The ball shines brightly until your blinded by the light, the next thing you know you\nhear a Crsytal's voice*");
    sleep(3);
    printf("CRYSTAL: %s are you ok?", name);
    loadingAnimation();
    BookThree();
    
}


void loadingAnimation(){
    printf("\n\nLoading ");
    for (int i = 0; i<=0; i++) {
        sleep(1);
        printf("\b\\");
        
        sleep(1);
        printf("\b|");
    
        sleep(1);
        printf("\b/");
    
        sleep(1);
        printf("\b-");
        sleep(1);
    }
    printf("\n\n");
}

int chosenNums[8];
int getRandnum(){
    int index = 0;
    srand(time(0));
    int randNum = rand() % 7;
    int arrSize = sizeof(chosenNums)/sizeof(chosenNums[0]);
    for(int i = 0; i <= arrSize - 1; i++){
        if(randNum != chosenNums[i]){
            chosenNums[index] = randNum;
            index++;
            return chosenNums[i];
        }
    }
}


void goNear(char *username){
    printf("You go near it and saw a brown and worn out grimoire with a\nclover logo. As your hand gets closer the shine from the grimoire\ngets brighter.\n\n");
    sleep(3);
    printf("\n*someone grabs your hand before you could touch it*\n\n");
    sleep(3);
    printf("DOCTOR: Who are you?\n\n");
    sleep(3);
    printf("YOU: Sorry, I wasn't gonna steal it. I just saw it glowing and it got me curious\n\n");
    sleep(3);
    printf("*Crystal intervenes and says sorry to the professor*\n\n");
    sleep(3);
    printf("CRYSTAL: Hey Doc, sorry about that. This is %s. I've brought her here\nbecause I thought you could help her.\n\n", username);
    sleep(3);
    printf("DOCTOR: OK...Um sorry about that. I was just worried that a person was\ntrying to steal my stuff...\n That grimoire glowed when your hand came near it. Did you feel anything?\n\n");
    sleep(3);
    printf("YOU: Yes, I felt like something was surging within me. Like it was reaching my soul\n\n");
    sleep(3);
    printf("DOCTOR: Grimoire is a special kind of book, in which they only choose a handful\nof people to be their master. A person who\n holds a grimoire can learn to read and use the spells stored within it.\nMaybe it's best to give it to you. As it seems that the grimoire determined you to be\nworthy of being a reader of its spells.\n\n");
    sleep(3);
    printf("DOCTOR: So Crystal what seems to be the problem. As I guessed you didn't come here without a good reason.\n\n");
    sleep(3);
    printf("CRYSTAL: You see…\n\n*CRYSTAL tells the whole story to the Doctor*\n\n");
    sleep(3);
    printf("DOCTOR: OK, I understand. Let's go to my office.\n\n");
    loadingAnimation(); 
    BookTwo();

}

void goToOffice(char *username){
    printf("*Both of you enter the Doctors office.*\n\n");
    sleep(3);
    printf("DOCTOR: Greetings Crystal. Have you been well?\n\nCRYSTAL: Yes Doc, and you?\n\nDOCTOR: Splendid. Who is this?\n\n");
    sleep(3);
    printf("CRYSTAL: This is my friend %s\n\n", username);
    sleep(3);
    printf("YOU: Hello.\n\nDOCTOR: Pleasure to meet you %s. How can I assist you?", username);
    sleep(3);
    printf("CRYSTAL: Well...\n\n");
    sleep(3);
    printf("*Crystal Proceeds to tell the whole story to the doctor*\n\n");
    sleep(3);
    printf("DOCTOR: OK. I understand.\n\n");
    sleep(3);
    printf("DOCTOR: Here I'll give you this book\n\n");
    sleep(3);
    printf("YOU: For what?\n\n");
    sleep(2);
    printf("DOCTOR: It will help you later on, for the challenge that you must take.\nIn order for you to go home\n\n");
    BookTwo();
}


void BookTwo(){
    printf("DOCTOR: What genre of books do you like?\n\n");
    sleep(3);
    printf("YOU: I like sci-fi stories, something like cyberpunk\n\n");
    sleep(3);
    printf("DOCTOR: Why sci-fi?\n\n");
    sleep(3);
    printf("YOU: Because I like technology, programming, network engineering, etc.\n Ever since I was in elementary I dabled with tech with the support of my father who\n worked in IT\n\n");
    sleep(3);
    printf("DOCTOR: OK. I think I have foud a way to bring back the memory you lost\nI will give you a crystal ball that will test you based on you interest.\n\n");
    sleep(3);
    printf("YOU: So that's why you asked  what genre of books I liked.\n\n");
    sleep(3);
    printf("*The Doctor puts a crystal ball on the table and it starts glowing.*\n\n");
    sleep(3);
    printf("DOCTOR: Questions will be given, each question you answer correctly will give you 1 point. \nGet 5 points and you will be given a wish\n\n");
    
    game();
    printf("Calculating Score\n\n");
    loadingAnimation();
    if(points >= 5){
        getWish();
    }else{
        if(playerGotBook == 1){
            printf("Since you got the book from the Doctor, you get a second chance");
            loadingAnimation();
            game();
        }else{
            printf("You didn't get enough points.");
            loadingAnimation();
            end();
        }
    }

}


void BookOne(char *playerName){
    int userInput;
    char username[20] = "Peace";
    printf("You are a bookworm, always reading books day and night. From firctionn to facts, horror to comedy.\nWhen someone asks you what book they should read, you already know the answer not by random but by examining\nthe kind of person they are and the type of book they would like.\n\n\n");

    sleep(5);
    printf("One day you go home, tired, hungry and itching to read the new book you just bought the other day entitled\n\"The Reader's Adventure to the Unknown\". At 9:00 pm you sit down in you bed and start reading the book. After 2 hours\nyou start to feel doozy and slowly fall asleep with the book beside you bed.\n\n\n");

    sleep(5);
    printf("You wake up in an unfamiliar forest. Unable to recall what happened after you dozed off. You hear something, a\nrattling sound near the bushes to you left. Then someone came out, a girl with a bow and arrow. Telling you to duck and\ncover as she was about to hit the boar behind you.\n\n\n");
    sleep(5);
    printf("*You duck out of the way*\n\n\n");
    sleep(5);
    printf("*She hits the boar behind you*\n\n\n");
    sleep(5);
    printf("After she hits the boar she says sorry to you, knowing that you've been put into danger. She asks\n\n\n");
    sleep(5);
    printf("Stranger: What is your name?\n\n");
    choiceOne:
        printf("YOUR CHOICES:\n1. Tell you name\n2. Don't tell her\n");
        scanf("%d", &userInput);
    if(userInput == 1){
        strcpy(username, playerName);
        printf("...I'm %s \n\n", username);
        strcpy(name, username);
        sleep(3);
    }
    else if(userInput == 2){
        printf("YOU: uhm...I'd rather not say\n\n");
        printf("Stranger: Ok...Yeah. I understand anonymity is important; especially when you're in an unknown place.\nFrom now on I will call you \"Peace\" as a symbol of our peaceful friendship\n\n");
        
        sleep(3);
    }else{
        goto choiceOne;
    }

    printf("Sorry about that, I'm Crystal, a professional adventurer from the town to the north named Negus.\nIf it's ok to ask, what were you doing here in the forest.\n\n");
    sleep(4);
    printf("YOU: I don't recall. I just woke up here\n\n");
    sleep(3);
    printf("CRYSTAL: Do you recall something, even just a little? Home? Family or Friends?\n\n");
    sleep(3);
    printf("YOU: No...The last thing I remember was reading a book before dozing off\n\n\n");
    sleep(3);
    printf("CRYSTAL: This is problematic...Ok, come with me, let's go to Chiba, its a town nearby. I know a doctor there.\nHe might be able to help you, especially after the situation you've just experienced. After that \nI'll treat you to dinner as an apology for earlier\n\n\n");
    sleep(4);
    printf("YOU: OK\n\n\n\n");
    sleep(3);
    printf("*You and Crystal Walk to Chiba*\n\n");
    sleep(3);
    loadingAnimation();
    printf("After arriving and going into the doctor's office you see something in the corner of you eye. A sort of flash\n\n");
    loadingAnimation();
    choiceTwo:
        printf("YOUR CHOICE:\n1. Go Near it\n2. Go Directly to the Doctors office\n\n");
        scanf("%d", &userInput);
    if(userInput == 1){
        goNear(username);
        playerGotBook = 1;
    }
    else if(userInput == 2){
        goToOffice(username);
    }else{
        goto choiceTwo;
    }
}   






