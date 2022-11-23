#include <stdio.h>

void main(){
    int size;
    printf("Size of the table:  ");
    scanf("%d", &size);

    if (size >= 1 && size <= 15)
    {
        for (int i = 1; i <= size; i++)
        {
            for (int b = 1; b <= size; b++)
            {
                printf("%d\t", i * b);
            }
            printf("\n");
            
        }
        
                
    }else{
        printf("Invalide Range!");
    }
    
}