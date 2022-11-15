#include <stdio.h>

void main(){
    int PassFlag = 0, tries = 5, input;
    do
    {
        printf("Input: ");
        scanf("%d", &input);
        if(tries != 0){
            if(input == 2004){
                PassFlag = 1;
            }else{
                printf("Incorrect Password!");
                tries--;
            }
        }else{
            PassFlag = 1;
        }
        
    } while (PassFlag != 1);
     
}