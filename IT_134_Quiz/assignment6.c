#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define size 100

void main(){

    int firstArr[size];
    int secondArr[size];

    srand(time(0));

    for (int i = 0; i < size; i++)
    {
        int randNum = rand() % 50 + 1;
        firstArr[i] = randNum;
        secondArr[i] = firstArr[i];
    }

    for(int b = 1; b <= size; b++){
        printf("%4d", firstArr[b-1]);
        if (b % 10 == 0)
        {
            printf("\n");
        }
        
    }

    printf("\n");

    for (int v = size - 1; v >= 0; v--)
    {
        printf("%4d", secondArr[v]);
        if(v % 10 == 0){
            printf("\n");
        }
    }
    
    


}