#include <stdio.h>

int main() {
    int n, num = 1;

    printf("Enter the number of rows for the triangle: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        // Print leading spaces to center the triangle
        for (int j = 1; j <= n - i; j++) {
            printf(" ");
        }

        // Print numbers in ascending order
        for (int j = 1; j <= i; j++) {
            printf("%d ", num);
            num++;
        }

        printf("\n");
    }

    return 0;
}
