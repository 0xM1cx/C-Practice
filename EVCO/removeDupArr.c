#include <stdio.h>

void main() {
    int size;
    printf("Enter size of array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter elements in array: \n");
    for (int i = 0; i < size; i++) {
        int element;
        int flag = 1;
        scanf("%d", &element);
        for (int j = 0; j < i; j++) {
            if (element == arr[j]) {
                flag = 2;
            }
        }

        if (flag != 2) {
            arr[i] = element;
        }
    }

    printf("Array after removing duplicates: ");
    for (int h = 0; h < (sizeof(arr) / sizeof(arr[0])); h++) {
        printf("%d", arr[h]);
    }
}