#include <stdio.h>

int main(){
    /*Write a C program that converts the number of minutes into days and years.*/
    // float M;
    // float days;
    // float years;

    // printf("Enter the number of minutes: ");
    // scanf("%f", &M);

    // days = M / 1440;
    // years = M / 525600;
    // float minRem = M % 1440.0;
    
    // printf("Days = %f:%f\n", days, minRem);
    // printf("Year = %f\n", years);

    float overspeed;
    float miles;
    printf("Enter value of Overspeed:  ");
    scanf("%f", &overspeed);


    if (overspeed<= 5) {
        printf("Fine is P100.00");
    }
    else if (overspeed<=10) {
        printf("Fine is P150.00");
    }
    else if (overspeed<=15) {
        printf("Fine is P200.00");
    }
    else if (overspeed>15) {

        printf("Fine is P%f plus", 200 + (miles * 50));
    }
    
    return 0;

}
