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

    int revarr[size];
    int count = 0;
    for (int b = size - 1; b >= 0; b--) {
        revarr[count] = arr[b];
        count++;
    }

    printf("The array in reverse order is: ");
    for (int j = 0; j < size; j++) {
        printf("%d ", revarr[j]);
    }
}