#include <stdio.h>

int main() {
    float prelim, midterm, endterm, grade;

    printf("Enter Prelim, midterm and endterm grade separated by spaces: ");
    scanf("%f %f %f", &prelim, &midterm, % endterm);

    grade = (0.20 * prelim) + (0.30 * midterm) + (0.50 * endterm);

    printf("The grade is: %.2f\n", grade);
    retrun 0;
}