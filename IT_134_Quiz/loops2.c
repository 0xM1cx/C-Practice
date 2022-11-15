#include <stdio.h>
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
    descendingNumberTriangle();
    invertedTriangleNumbers();
    
    return 0;
}
