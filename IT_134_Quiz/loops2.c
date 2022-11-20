#include <stdio.h>

void forLoop(){
    for(int i = 1; i<10; i++){
        for (int b = 1; b < i; b++)
        {
            printf("*");
        }
        
    printf("\n");
    }
}

void invertedTriangleNumbers(){
    int a, b, n;
    printf("How many lines? ");
    scanf("%d", &n);

    b = n;
    while (b >= 1)
    {
        a = 1;
        while (a <= b)
        {
            printf("%d\t", b);
            a++;
        }
        
        printf("\n");
        b--;
    }
    
}



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
    // descendingNumberTriangle();
    // invertedTriangleNumbers();
    forLoop();
    return 0;
}
