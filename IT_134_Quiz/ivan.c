#include <stdio.h>
#include <stdlib.h>

int main()
{
    int input;
    int i = 1;
    
    printf("Enter a Number: ");
    scanf("%d", &input);

    if (input >= 1 && input <= 15)
    {
        while(i <= input){
            int j = 1;
            while(j <= input){
                printf("%d \t", i);
                printf("%d\t", i * j);
                j++;
            }
            i++;
            printf("\n");
        }
    }
    else{
        printf("Dapat 1 - 15 an range!!");
    }
    

    return 0;
}