#include <stdio.h>

void reverseSparse(int sourcecode[7][3], int targetArr[10][10]) {
    for (int i = 0; i < 7; i++) {
        targetArr[sourcecode[i][0]][sourcecode[i][1]] = sourcecode[i][2];
        printf("%d %d %d\n", sourcecode[i][0], sourcecode[i][1], sourcecode[i][2]);
    }

    for (int t = 0; t < 10; t++) {
        for (int y = 0; y < 10; y++) {
            printf("%d ", targetArr[t][y]);
        }
        printf("\n");
    }
}

void main() {
    int sourcecode[7][3] = {
        {1, 2, 5},
        {2, 4, 1},
        {3, 1, 2},
        {9, 5, 2},
        {5, 10, 8},
        {8, 6, 9},
        {7, 8, 10}};

    int targetArr[10][10];
    reverseSparse(sourcecode, targetArr);
}