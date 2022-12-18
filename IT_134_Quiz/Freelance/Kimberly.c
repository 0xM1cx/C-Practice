#include <stdio.h>
#include <windows.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define size 5

void goToOffice(), goNear(), BookTwo(), BookOne(char *playerName), loadingAnimation(), getWish(), end(), game(), BookThree(), BookThreePartTwo(), BookThreeFinale();
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

void BookThreeFinale(){
    system("cls");
    printf("*The final showdown begins*\n\n\n");
    sleep(2);
    int score = 0;
    int userInput;

    printf("Unix is written in what language?\n");
    printf("1. C#\t2. C\n3.Java\t4.COBOL\n");
    printf("Number of your answer: ");
    scanf("%d", &userInput);
    if(userInput == 2){
        score++;
    }

    printf("Which of the following is an extension of image file?\n");
    printf("1. .mkv\t2. .txt\n3. .gif\t4. .vdf\n");
    printf("Number of your answer: ");
    scanf("%d", &userInput);
    if(userInput == 3){
        score++;
    }

    printf("The main memory of a computer system is?\n");
    printf("1. Non-volatile\t2. volatile\n3. restricted\t4. unrestricted\n");
    printf("Number of your answer: ");
    scanf("%d", &userInput);
    if(userInput == 2){
        score++;
    }

    printf("URL stand for?\n");
    printf("1. Uniform Resource Locator\t2. Uniform Record Locator\n3. Uninterrupted resource Locator\t4. Uninterrupted record locator\n");
    printf("Number of your answer: ");
    scanf("%d", &userInput);
    if(userInput == 1){
        score++;
    }

    printf("SSL stands for?\n");
    printf("1. Secure server layer\t2. Secure system level\n3. Secure server level\t4. Secure Sockets Layer\n");
    printf("Number of your answer: ");
    scanf("%d", &userInput);
    if(userInput == 4){
        score++;
    }

    printf("How many bits is a nibble?\n");
    printf("1. 4 bits\t2. 1 bits\n3. 3 bits\t4. 10 bits\n");
    printf("Number of your answer: ");
    scanf("%d", &userInput);
    if(userInput == 1){
        score++;
    }

    printf("Where is the computer firmare present\n");
    printf("1. Cache Memory\t2. Non-volatile memory\n3. Volatile Memory\t4. SSD/HDD\n");
    printf("Number of your answer: ");
    scanf("%d", &userInput);
    if(userInput == 2){
        score++;
    }

    printf("Computer word size is a multiple of?\n");
    printf("1. 100 bits\t2. 16 bits\n3. 10 bits\t4. 1024 bits\n");
    printf("Number of your answer: ");
    scanf("%d", &userInput);
    if(userInput == 2){
        score++;
    }

    printf("What does OCR stand for?\n");
    printf("1. Optical Card Reader\t2. Office Cash Receiver\n3.Optical Character Reader\t4. Online Computer Retrieval\n");
    printf("Number of your answer: ");
    scanf("%d", &userInput);
    if(userInput == 3){
        score++;
    }

    printf("In a computer, a number which is used to identify the location of a word in memory is called?\n");
    printf("1. code\t2. location\n3.address\t4. binary number\n");
    printf("Number of your answer: ");
    scanf("%d", &userInput);
    if(userInput == 3){
        score++;
    }

    if(score >= 8){
        printf("JOHN: tsk, very well. I am a man of my word.\n");
        sleep(2);
        system("cls");
        printf("JOHN: Here is the scroll\n");
        sleep(2);
        printf("*crystal punches john in the face*");
        sleep(2);
        printf("CRYSTAL: I won't let you off the hook. Your coming with me to the town gaurd.\nWhere you will be tried for your sins\n");
        sleep(2);
        printf("*You and crystal go back to the town*");
        sleep(2);
        printf("CRYSTAL: GAURDS! John is accused of stealing other worldy beings memories\n and illegal transportation\n");
        sleep(2);
        printf("*John is taken by the gaurds to the holding cell, awaiting his trail*\n\n");
        sleep(2);
        printf("CRYSTAL: So lets go to the town center to get something to eat\n before you go home\n");
        sleep(2);
        printf("*You and crystal go to the town tavern to get something to eat*");
        sleep(2);
        printf("CRYSTAL: You know, you can use that scoll to come back here anytime you want.\n I mean your DNA is registered on it so its yours\n");
        sleep(2);
        printf("YOU: Yeah, I would of course.");
        sleep(2);
        printf("*Both you and crystal go to the town fountian before you leave*");
        sleep(2);
        printf("CRYSTAL: So this is it huh. Well it was nice to go on an adventure with you\n");
        sleep(2);
        printf("YOU: Don't worry when I come back, we'll go on more adventures. Promise\n");
        sleep(2);
        printf("*You start to open the scoll and read the text*\n");
        sleep(2);
        printf("*You start to fade away*\n");
        sleep(2);
        printf("*You arrive at your room stil the same like you didn't leave, the only difference it its daytime now*\n");
        sleep(2);
        printf("*You look at the toy bow in your wall and wonder.\n*");
        sleep(2);
        printf("YOU: What adventure will I have next when I come back");

        sleep(4);
        system("cls");
        printf("\n\n\n\nTHANK YOU FOR PLAYING!!!\n\n");
        printf("Exiting Game...");
        loadingAnimation();
    }else{
        printf("You've failed to get the required points of 8 and greater");
        sleep(3);
        system("cls");
        BookThreeFinale();
    }
    
}


void BookThreePartTwo(){
    printf("*A flash appears blinding you\n*");
    sleep(2);
    printf("*As you start to wake up, you see a flashes of you memory\n and you found out a pilgrim with a gold star badge stole your memories*\n");
    sleep(2);
    printf("*You woke up and see the doctor and Crystal standing in front*\n");
    sleep(2);
    printf("CRYSTAL: %s are you ok?\n", name);
    sleep(2);
    printf("YOU: Yeah, I'm OK\n");
    sleep(2);
    printf("CRYSTAL: What did you see?\n");
    sleep(2);
    printf("YOU: I saw a pilgrim with a gold star badge\nBut I don't know who it is\n\n");
    sleep(2);
    printf("CRYSTAL: A pilgrim with a gold badge...\n");
    sleep(2);
    printf("CRYSTAL: There is one person who I know has that badge\n");
    sleep(2);
    printf("CRYSTAL: Its John, the world traveller\n");
    sleep(2);
    printf("YOU: World Traveller?");
    sleep(2);
    printf("CRYSTAL: Like a traveller but between world, they are mostly scientist\n");
    sleep(2);
    printf("CRYSTAL: John the Pilgrim is one of the worst, he's greedy and a total jerk, no wonder why he took your memories.\n");
    sleep(2);
    printf("YOU: But why would he take it?\n");
    sleep(2);
    printf("Why don't we find out for ourselves. Thanks DOC for helping us\n");
    sleep(2);
    printf("DOCTOR: No problem...Be careful you two\n");
    sleep(2);

    system("cls");

    printf("*You and Crystal journey to the lake where John lives*\n\n");
    sleep(2);
    printf("*As you enter the lodge in the lake, you see John reading a book*\n");
    sleep(2);
    printf("*Due to Crystal impatience, she recklessly approaches him*\n");
    sleep(2);
    printf("JOHN: WHO ARE YOU?\n\n");
    sleep(2);
    printf("*John looks at you*");
    sleep(2);
    printf("JOHN: Ah, you the girl from earth\n");
    sleep(2);
    printf("YOU: You recognize me?\n");
    sleep(2);
    printf("JOHN: Of course, you one of the most sweetest memories of all the worlds that i've travelled\n");
    sleep(2);
    printf("YOU: so you've taken other people memories. But why did you transport me here?");
    sleep(2);
    printf("JOHN: Not really, stealing is against the law of course and you can't transfer memories between worlds\nunless you can transport the person first to your world and take their memories from there\n\n");
    sleep(2);
    printf("YOU: That's why, you doozed me off and transported me here, then after you stole my memories you left me in the forrest\n");
    sleep(2);
    printf("JOHN: You got it. But why come to me, I presumed you gained them back\nI mean your with Crystal the famous adventurer\nI'm sure her friend DOC would have find a way\n");
    sleep(2);
    printf("JOHN: Do you wan't revenge? or is it that you can't go home\n");
    sleep(2);
    printf("*John saw the look on your face as he said the other possibility*\n\n");
    sleep(2);
    printf("JOHN: I see you can't go home, HAHAHAH.\nOf course you can't I'm the one who brought you here with a TCP scroll.\n");
    sleep(2);
    printf("CRYSTAL: TCP scoll?\n\n");
    sleep(2);
    printf("JOHN: Its a new invention of mine, it allows me to tranfer large life force in segements\n and prevents any loss in those segments because when each segement is transported\n my scroll check if it has been truly transported before transporting the other segment\n\n");
    sleep(2);
    printf("JOHN: The only problem, the only way to go back is to get the same scroll to transport you back\nThat's because when a person is transported via TCP scroll their DNA is ingrained into the scroll\n\n");
    sleep(2);
    printf("*Crystal points her bow at john*\n");
    sleep(2);
    printf("JOHN: Woah, no need to get violent. I'll give you the scroll if you defeat me that is\n");
    sleep(2);
    printf("CRYSTAL: You think this is a game?\n");
    sleep(2);
    printf("JOHN: Yes HAHAH, All the searching, fighting has led to this moment. Isn't it exciting HAAHAH\n");
    sleep(2);
    printf("JOHN: Shall we begin");
    sleep(2);
    printf("The rules of the game is simple, I will give you questions and yo just have to answer them");
    sleep(2);

    BookThreeFinale();


}


void BookThree(){
    char _userAns[30];
    int riddleScore = 0;
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


    char answers[10][30] = {"Keyboard", "Mouse", "Monitor", "Internet Explorer", "Windows"};
    system("cls");
    printf("I can write without a pen, without the number 10, what am I?");
    scanf(" %s", _userAns);
    if(strcmp(_userAns, answers[0]) == 0){
        riddleScore++;
    }
    sleep(2);
    system("cls");

    printf("I have a tail and two flat ears. I move with no feet");
    scanf(" %s", _userAns);
    if(strcmp(_userAns, answers[1]) == 0){
        riddleScore++;
    }
    sleep(2);
    system("cls");

    printf("A box to anywhere. Just watch for my glare.");
    scanf(" %s", _userAns);
    if(strcmp(_userAns, answers[2]) == 0){
        riddleScore++;
    }
    sleep(2);
    system("cls");
    
    printf("I move slower than molasses, if you use me, you probably wear glasses.");
    scanf(" %s", _userAns);
    if(strcmp(_userAns, answers[3]) == 0){
        riddleScore++;
    }
    sleep(2);
    system("cls");

    printf("25 years old, but only turned 10");
    scanf(" %s", _userAns);
    if(strcmp(_userAns, answers[4]) == 0){
        riddleScore++;
    }
    sleep(2);
    system("cls");

    if(riddleScore >= 3){
        printf("\"You've done well. I will now grant you're wish\"");
        sleep(2);
        system("cls");
        BookThreePartTwo();

    }else{
        printf("\"You've failed to meet the required score of 3 correct answers.\n I cannot give you your wish.\"");
        sleep(2);
        system("cls");
        BookThree();
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






