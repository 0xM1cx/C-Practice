#include <stdio.h>

int main(){

    int ctrl1, ctrl2, lines;
    printf("How many lines? ");
    scanf("%d", &lines);
    ctrl2 = lines;
    while (ctrl2 >= 1)
    {
        ctrl1 = lines;
        while (ctrl1 >= ctrl2)
        {
            printf("*");
            ctrl1--;
        }
        // ctrl1 = 1;
        // while (ctrl1 <= ctrl2)
        // {
        //     printf("*");
        //     ctrl1++;  
        // }

        // ctrl1 = 1;
        // while (ctrl1 <= ctrl2)
        // {
        //     printf(" ");
        //     ctrl1++;
        // }

        // ctrl1 = lines;
        // while (ctrl1 >= ctrl2)
        // {
        //     printf("*");
        //     ctrl1--;
        // }
        printf("\n");
        ctrl2--;

    }
    

    return 0;
}