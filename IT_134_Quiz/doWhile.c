#include <stdio.h>

void main(){
    int PassFlag = 0, tries = 4, input;
    do
    {
        printf("Input: ");
        scanf("%d", &input);
        if(tries != 0){
            if(input == 2004){
                PassFlag = 1;
            }else{
                printf("Incorrect Password!\n");
                tries--;
            }
        }else{
            PassFlag = 1;
        }
        
    } while (PassFlag != 1);
     
}