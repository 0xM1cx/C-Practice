#include <stdio.h>
#include <string.h>

int numberOne(){
    /*Write a program that will print the rightmost digit of an integer.*/
    int num;
    printf("Enter an integral number: ");
    scanf("%d", &num);

    char str[100];
    sprintf(str, "%d", num);

    char lastDigit = str[sizeof()];
    printf("%c", lastDigit);
}

int numberTwo(){

}

int main(){
    int userInput;
    printf("INPUT: ");
    scanf("%d", &userInput);

    if(userInput == 1){
        numberOne();
    }

    else if(userInput == 2){
        numberTwo();
    }
}