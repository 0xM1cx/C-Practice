#include <stdio.h>

int main(){
    /*Create a C program that accepts an input in inches and then displays the equivalent height in terms of 
     * foot and inches*/

    int inchs, foot, height, extra_inches;
    printf("What is your height(in inches):  ");
    scanf("%d", &inchs);
    height = inchs / 12;
    extra_inches = inchs % 12;
    printf("Your height is %d' %d\" ", height, extra_inches);
    
    
    return 0;
}
