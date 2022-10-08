// Write a program to print the user's name, age, and birthdate. Note the age must be taking by the current year and date of birth.

#include <stdio.h>
#include <stdlib.h>
#define MAX_LIMIT 100
#include <string.h>

// Print out User Inputs
int exerciseSix(){
    char crush[20];
    printf("Name han imo crush:  ");
    scanf("%s", &crush);
    printf("%s", crush);

}
int exerciseOne() {
    int currentDate = 2022;
    int birthYear;
    char name[20];

    printf("Who are you: ");
    scanf("%s", name);

    printf("What is the year were you born on: ");
    scanf("%d", &birthYear);
    int age = currentDate - birthYear;

    printf("To confirm you are %s and you are %d years old \n", name, age);
}

// Print out the letter F using #
int exerciseTwo() {
    int n = 1;
    for(int i = 1; i <= 6; ++i){
        if (i == 1){
           n = 5;
        }
        else if(i == 3){
            n = 4;
        }else{
            n = 1;
        }
        for(int b = 1; b <=n; ++b){
            printf("#");
        }
        printf("\n");
    }
}

// Print a askterisk pattern in which the number of askterisks are depended on the user input
int exerciseThree(){
    int n;
    printf("What is n? ");
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        for(int b = 1; b <= i; b++){
            printf("*");
        }
        printf("\n");
    }
    printf("\n");
    for(int i = n; i >= 0; --i){
        for(int b = 1; b <= i; b++){
            printf("*");
        }
        printf("\n");
    }

}

// Write a program to print out a string in reverse
int exerciseFour(){
    char Uinput[20];
    printf("String: ");
    scanf("%s", Uinput);
    printf("%c", Uinput[-1]);
}
int exerciseFive(){
    // Write a program in C to display n terms of natural number and their sum
    int n;
    printf("What is n? ");
    scanf("%d", &n);
    int sum = 0;
    for(int i = 1; i <= n; ++i){ 
        printf("%d ", i);
        sum += i;
    }
    printf("\n");
    printf("The sum of all the numbers given is %d \n", sum);
}


int main(){
    int Userinput;
    printf("Type a number that corresponds to the exercise \n");
    printf("E.g 1 for exerciseOne\n Type a number: ");
    scanf("%d", &Userinput);
    if(Userinput == 1) {
        exerciseOne();
    }
    else if(Userinput == 2){
        exerciseTwo();
    }
    else if(Userinput == 3){
        exerciseThree();
    }
    else if(Userinput == 4){
        printf("%c", exerciseFour());
    }
    else if(Userinput == 5){
        exerciseFive();
    }
    else if(Userinput==6){
        exerciseSix();
    }
    else{
        exit(0);
    }
    
}
