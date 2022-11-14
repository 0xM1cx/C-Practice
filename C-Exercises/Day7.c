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

    int a = 1;
        srand(time(0));
    while (a <= 5)
    {
        int randomNumber = rand();
        printf("%d. %d\n", a, randomNumber);
        a++;
        
    }
    


}
