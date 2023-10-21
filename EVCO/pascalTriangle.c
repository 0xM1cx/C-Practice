#include <stdio.h>
#define MAX 100
void main() {
    int size, arr[MAX][MAX];

    printf("Enter the number of rows: ");
    scanf("%d", &size);

    arr[0][0] = 1;
    arr[1][0] = arr[1][1] = 1;
    for (int i = 2; i < size; i++) {
        arr[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
        }
    }

    for (int i = 0; i < size; i++) {

        for (int j = 0; j <= i; j++) {
            printf(" %2d", arr[i][j]);
        }
        printf("\n");
    }
}