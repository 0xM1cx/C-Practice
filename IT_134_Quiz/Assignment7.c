#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define size 7



void main(){

    
    // I created an array of integers from 1 to 49 
    // int array[size][size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
    // 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 
    // 47, 48, 49}; // Initialize the 7x7 array

    int array[size][size];
    int counter = 1;
    // for (int a = 0; a < size; a++)
    // {
    //     for (int f= 0; f < size; f++)
    //     {
    //         array[a][f] = counter;
    //         counter++;
    //     }
        
    // }
    int t = 0, r = 0;
    int cnt = 1;
    while(t < size){
        while(r < size){
            array[t][r] = cnt;
            cnt++;
            r++;
        }
        t++;
    }
    

    // This loop below is used to display the loop as specified by the instructions(girls)
    for (int i = 0; i <size; i++)
    {
        for (int b = 0; b < size; b++) // notice that the size is 7. So this loop will run from array[0] to array[6]
        {
            printf("%4d", array[b][i]); // the i represent the row and the b represents the column
        }
        printf("\n");   
    }

  
    
}