#include <stdio.h>

/*
NAME: Shawn Michael A. Sudaria
SECTION & YEAR: 1B
GITHUB: https://github.com/0xM1cx
FACEBOOK: https://www.facebook.com/Sudaria.Shawn

*/


int main(){
    /*Create a C program that accepts the distance traveled and
    displays the total cost using the rate for every kilometer travelled in the
    given table below.*/

    int distance;
    printf("Distance Travelled:  ");
    scanf("%d", &distance);

    if(!(distance < 0)){
        if(distance >= 0 && distance <= 10){
            printf("Cost is %.2f\n", distance * 5.00);
        }
        else if(distance > 10 && distance <= 50){
            printf("Cost is %.2f\n", distance * 8.00);
        }else if(distance > 50 && distance < 100){
            printf("Cost is %.2f\n", distance * 10.00);
        }
        else if(distance > 100){
            printf("Cost is %.2f\n", distance * 12.00);
        }
    }else{
        main();
    }
}
