#include <stdio.h>

void main() {
    int size;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);
    int arr[size];
    int unique[100];
    printf("Enter the elements of the array: \n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int count = 0;

    for (int i = 0; i < size; i++) {
        int flag = 0;
        for (int j = 0; j < count; j++) {
            if (arr[i] == unique[j]) {
                flag = 1;
                break;
            }
        }
        if (flag < 1) {
            unique[count] = arr[i];
            count++;
        }
    }

    printf("Unique Elements: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", unique[i]);
    }
}