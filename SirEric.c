#include <stdio.h>
#include <stdlib.h>

int main(){
    int crtl1, ctrl2 = 1, vertical;
    printf("How many lines? ");
    scanf("%d", &lines);
    while (ctrl2 <= lines)
    {   
        crtl1 = 1;
        char space = '_';
        
        int crtl3 = 1;
        while(crtl3 <= lines)
        {
            printf("%c",space);
            crtl3++;
        }
        
        while (crtl1 <= ctrl2)
        {
            
            printf("*");
            crtl1++;
        }
        printf("\n");
        ctrl2++;
        
    }

    return 0;
    
    
}

