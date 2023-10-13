#include <stdio.h>

void main() {
    int size;
    printf("Enter the size of array: ");
    scanf("%d", &size);

    float arr[size];
    printf("Enter %d elements of array: \n", size);
    for (int i = 0; i < size; i++) {
        float el;
        scanf("%f", &el);
        arr[i] = el;
    }

    float sum = 0;

    for (int b = 0; b < size; b++) {
        sum += arr[b];
    }

    printf("The average of the array is: %.2f", sum / size);
}