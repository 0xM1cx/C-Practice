#include <stdio.h>
#include <string.h>

int numberOne(){
    /*Write a program that will print the rightmost digit of an integer.*/
    int num;
    printf("Enter an integral number: ");
    scanf("%d", &num);

    char str[100];
    sprintf(str, "%d", num);


    printf("%c \n", str[strlen(str)-1]);
}

// int numberTwo(){
//     /*Write a program that will get four numbers from the sue and display the following output.*/
//     float numOne, numTwo, numThree, numFour;
//     printf("Enter the first number: ");
//     scanf("%d", &numberOne);
//     printf("Enter the second number: ");
//     scanf("%d", &numberTwo);
//     printf("Enter the third number: ");
//     scanf("%d", &numberThree);
//     printf("Enter the fourth number: ");
//     scanf("%d", &numFour);

//     printf("******** average is %f ********", (numberOne + numberTwo + numThree + numFour) / 4);

//     printf("First number: %d -- ", numberOne);
// }

int numberThree(){
    /*Write a C program that calculate a student's average score for a course 
    with 4 quizzes, 2 midterms and a final score. The quizzes are 
    weighted 30%, the midterms 40% and the final 30%*/

  
}

int main(){
    int userInput;
    printf("INPUT: ");
    scanf("%d", &userInput);

    if(userInput == 1){
        numberOne();
    }

    else if(userInput == 2){
        // numberTwo();
    }
    else if(userInput == 3){
        numberThree();
    }
}