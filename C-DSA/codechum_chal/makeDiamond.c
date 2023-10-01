#include <stdio.h>

void main(){
    int addInt;
    printf("Enter an odd integer: ");
    scanf("%d", &addInt);
    int ctr = 3;
    for(int i = 1; i <= addInt; i++){
        for(int j = ctr; j >= 1; j--){
            printf("\t");
        }
        for(int b = 1; b <= i; b++){
            if((i % 2) != 0){
                printf("*"); 
            }
        }
        ctr--;
        printf("\n");
    }

    for(int i = addInt-1; i >= 1; i--){
        for(int b = i; b >= 1; b--){
            if((i % 2) != 0){
                printf("*"); 
            }
        }
        printf("\n");
    }
}