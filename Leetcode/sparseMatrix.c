#include <stdio.h>
#include <stdlib.h>

void main() {
    int sparseMatrix[][5] = {
        {0, 0, 0, 3, 0},
        {16, 0, 0, 47, 11},
        {0, 0, 88, 0, 23},
        {0, 17, 0, 0, 0},
        {0, 0, 12, 0, 0}};

    int x, y;
    int altern[9][3];
    int rowCount = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (sparseMatrix[i][j] != 0) {
                altern[rowCount][0] = i;
                altern[rowCount][1] = j;
                altern[rowCount][2] = sparseMatrix[i][j];
            }
        }
        rowCount++;
    }

    printf("| %d |", altern[0][0]);
    printf(" %d |", altern[0][1]);
    printf(" %d |", altern[0][2]);
}

    
