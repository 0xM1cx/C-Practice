#include <stdio.h>

void descendingNumberTriangle(){
    int a, b, n;
    printf("How many lines? ");
    scanf("%d", &n);
    b = n;
    while (b >= 1)
    {
        a = n;
        while (a >= b)
        {
            printf("%d  ", a);
            a--;
        }
        
        printf("\n");
        b--;
    }
    
}

int main(){
    descendingNumberTriangle();
    
    return 0;
}