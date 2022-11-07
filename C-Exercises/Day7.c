#include <stdio.h>

void main() {
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int biggest;

    for(int i = 0; i < sizeof(array)/sizeof(int); i++){
        if(biggest < array[i]){
            biggest = array[i];
        }else{
            continue;
        }

        printf("The biggest value is: %d\n", biggest);
    }
}
