#include <stdio.h>

void main() {
    int size;
    printf("Enter size of array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter elements of array: \n");
    for (int i = 0; i < size; i++) {
        int el;
        scanf("%d", &el);
        arr[i] = el;
    }

    int biggest = 0;
    for (int b = 0; b < size; b++) {
        if (arr[b] > biggest) {
            biggest = arr[b];
        }
    }

    printf("Maximum element in array is: %d", biggest);
}