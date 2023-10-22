#include <stdio.h>

void getProduct(int row1, int col1, int row2, int col2, int matrix1[row1][col1], int matrix2[row2][col2], int matrix3[10][10]) {
    int row3 = 0, col3 = 0;
    for (int i = 0; i <= row1; i++) {
        for (int j = 0; j <= col2; j++) {
            matrix3[i][j] = 0;
            for (int k = 0; k < col1; k++) {
                matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    printf("\nProduct of the Matrices: \n");
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            printf("%d ", matrix3[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int row1, col1, row2, col2;
    printf("Enter rows and columns for the first matrix: ");
    scanf("%d %d", &row1, &col1);
    printf("Enter rows and columns for the second matrix: ");
    scanf("%d %d", &row2, &col2);

    int matrix1[row1][col1], matrix2[row2][col2];
    if (col1 != row2) {
        printf("Matrices cannot be multiplied.");
        return 0;
    }

    printf("Enter elements of the first matrix: \n");
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col1; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("\nEnter elements of the second matrix: \n");
    for (int i = 0; i < row2; i++) {
        for (int j = 0; j < col2; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    int matrix3[row1][col2];

    getProduct(row1, col1, row2, col2, matrix1, matrix2, matrix3);
}