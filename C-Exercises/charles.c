#include <stdio.h>

int main(){
    /*Write a C program that converts the number of minutes into days and years.*/
    float M;
    float days;
    float years;

    printf("Enter the number of minutes: ");
    scanf("%f", &M);

    days = M / 1440;
    years = M / 525600;
    float minRem = M % 1440.0;
    
    printf("Days = %f:%f\n", days, minRem);
    printf("Year = %f\n", years);

    return 0;

}
