#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main(){
    // int n;
    // printf("What is n? ");
    // scanf("%d", &n);
     
    // for(int i = 0; i <= n; i++){
    //     for(int j = 0; j <= i; j++){
    //         printf("%c\t", 0==1);
    //     }
    //     printf("\n");
    // }
    
    srand(time(0));
    int num = rand() % 3 + 1;
    printf("%d", num);    
}