#include <stdio.h>

int main() {
    float length, width;

    printf("Enter the length and width; ex. 3 3: ");
    scanf("%f %f", &length, &width);

    float area = length * width;
    float perimeter = 2 * (length + width);

    printf("Area of rectangle: %.2f\n", area);
    printf("Perimeter of rectangle: %.2f\n", perimeter);

    return 0;
}