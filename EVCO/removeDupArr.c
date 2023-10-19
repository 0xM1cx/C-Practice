#include <stdio.h>

void main() {
    int size;
    printf("Enter size of array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter elements in array: \n");
    for (int i = 0; i < size; i++) {
        int element;
        scanf("%d", &element);
        arr[i] = element;
    }

    for (int j = 0; j < size; j++) {
        for (int n = j + 1; n < size;) {
            if (arr[j] == arr[n]) {
                for (int m = j; m < size - 1; m++) {
                    arr[m] = arr[m + 1];
                }
                size--;
            } else {
                n++;
            }
        }
    }

    printf("Array after removing duplicates: ");
    for (int h = 0; h < size; h++) {
        printf("%d ", arr[h]);
    }
}