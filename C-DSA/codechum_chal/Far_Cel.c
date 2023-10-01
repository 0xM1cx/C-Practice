#include <stdio.h>

void main() {
    float far, cel;

    printf("Enter temperature in Fahrenheit: ");
    scanf("%f", &far);

    cel = (far - 32) * 5 / 9;
    printf("Temperature in Celsius: %.2f", cel);
}