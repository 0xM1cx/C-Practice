#include <stdio.h>

void main() {
    int size, sum = 0;
    printf("Enter the size of the matrix: ");
    scanf("%d", &size);
    int arr[size][size];
    printf("Enter the elements of the matrix: \n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    int count = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i][count];
        count++;
    }

    printf("The diagonal sum of the matrix is: %d", sum);
}