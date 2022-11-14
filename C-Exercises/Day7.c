#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void main() {
    // int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    // int biggest;

    // for(int i = 0; i < sizeof(array)/sizeof(int); i++){
    //     if(biggest < array[i]){
    //         biggest = array[i];
    //     }else{
    //         continue;
    //     }

    //     printf("The biggest value is: %d\n", biggest);
    // }
    int sum = 0;
    int a = 0;
    srand(time(0));
    int num[5];

    while (a <= 4)
    {
        int randomNumber = rand() % 10 + 1;
        num[a] = randomNumber;

        if(a != 4){
            printf("%d +", randomNumber);
        }else{
            printf("%d = ", randomNumber);
        }
        a++;
        sum += randomNumber;
    }
    
    printf("%d", sum);




}
