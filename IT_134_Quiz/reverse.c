#include <stdio.h>

void main(){
    int input, n = 5, b; 
    printf("INPUT: ");
    scanf("%d", &input);
    for(; input != 0;){
        printf("%d", input % 10);
        input /=10;
        
    }
}