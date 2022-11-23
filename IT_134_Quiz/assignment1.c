#include <stdio.h>

void main(){
    /*Create a program that accepts an integer. The Program displays a pattern. If the input is an
    even number, the next number is half of the previous number. If the number is odd, the next number
    is multiplied by 3 and added by 1... The next number is displayed until the next number is 1.*/

    int userInt; // variable gamit para ig store han value from the user
    printf("INTEGER: ");
    scanf("%d", &userInt); // na accept hin integer
    printf("%d\n", userInt); // print an original na input

    for(;userInt != 1;){ // mag run la kun an userInt dire pa 1
        if (userInt % 2 == 0) // check kun even
        {
            userInt /= 2; // kun even, base sa instruction ig kuha an half tapos ito na half amo na an bago na value han userInt
            printf("%d\n", userInt); // print na an bago na value han userInt
        }else{
            userInt  = (userInt * 3) + 1; // kun odd amo ine an operation base ha instructions
            printf("%d\n", userInt); // print an bago na value han userInt
        }
        // after hito, ma balik na hiya ha igbaw na loop para ig check an condition, tapos basa balik paubos an compiler tutob mag 1 an userInt
    }


}