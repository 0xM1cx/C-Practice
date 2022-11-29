#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define size 7

void main(){
    srand(time(0));

    
    // Make a 7x7 2 dimensional array
    int array[size][size];
    for (int i = 0; i <size; i++)
    {
        for (int b = 0; b < size; b++)
        {
            array[i][b] = rand() % 50 + 1;
        }     
    }

    
    for (int i = 0; i <size; i++)
    {
        for (int b = 0; b < size; b++)
        {
            printf("%4d", array[i][b]);
        }
        printf("\n");
           
    }

    printf("%d", array[1][1]);
    
}