#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void main(){

    /*Create a program that displyas a 10 x 10 random integers from 1 to
    50. The program counts the number of odd integers as well as the 
    number of even integers. The sum of both even numbers and odd numbers
    are also displayed.
    
    SAMPLE OUTPUT:
    1 2 3 5 2 6 2 4 7 2
    4 5 2 6 4 8 5 6 6 3
    1 2 4 3 6 8 5 9 5 8
    4 3 6 8 2 9 4 8 4 0
    
    Number of Odd:
    Number of Even:
    Sum of Odd:
    Sum of Even: */
    
    srand(time(0));
    int randNum;
    int numberOfOdd = 0;
    int numberOfEven = 0;
    int sumOfEven = 0, sumOfOdd = 0;

    for (int i = 1; i < 10; i++)
    {
        for (int b = 0; b < 10; b++)
        {
            randNum = rand() % 50 + 1;
            if (randNum % 2 == 0)
            {
                numberOfEven += 1;
                sumOfEven += randNum;
            }else{
                numberOfOdd += 1;
                sumOfOdd += randNum;
            }

            printf("%4d", randNum);
            
        } 
        printf("\n");
    }

    printf("\nNumber of Even: %d", numberOfEven);
    printf("\nNumber of Odd: %d", numberOfOdd );
    printf("\nSum of Odd: %d", sumOfOdd);
    printf("\nSum of Even: %d", sumOfEven);
    


}