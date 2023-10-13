#include <stdio.h>
void main() {
    int size;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);
    int dups[size];
    int arr[size];
    printf("Enter %d elements in the array: \n", size);
    for (int i = 0; i < size; i++) {
        int el;
        scanf("%d", &el);
        arr[i] = el;
    }

    int count = 0;
    for (int b = 0; b < size; b++) {
        for (int j = b + 1; j < size; j++) {
            if (arr[b] == arr[j]) {
                dups[b] = arr[b];
                count++;
                break;
            }
        }
    }
    printf("Duplicate elements in the array are: ");
    for (int n = 0; n < count; n++) {
        printf("%d ", dups[n]);
    }
}