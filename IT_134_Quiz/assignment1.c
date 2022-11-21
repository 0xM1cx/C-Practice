#include <stdio.h>

void main(){
    /*Create a program that accepts an integer. The Program displays a pattern. If the input is an
    even number, the next number is half of the previous number. If the number is odd, the next number
    is multiplied by 3 and added by 1... The next number is displayed until the next number is 1.*/

    int userInt;
    printf("INTEGER: ");
    scanf("%d", &userInt);

    for(;userInt != 1;){
        if (userInt % 2 == 0)
        {
            userInt /= 2;
            printf("%d\n", userInt);
        }else{
            userInt  = (userInt * 3) + 1;
            printf("%d\n", userInt);
        }
        
    }


}