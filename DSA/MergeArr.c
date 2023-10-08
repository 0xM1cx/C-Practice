#include <stdio.h>
#include <string.h>
#include <windows.h>

void Arr1(char arr3[10][50], char arr1[10][50], int count1, int count3) {
    strcpy(arr3[count3], arr1[count1]); // use string copy
    count1++;
}

void Arr2(char arr3[10][50], char arr2[10][50], int count2, int count3) {
    strcpy(arr3[count3], arr2[count2]);
    count2++;
}

void main() {

    char arr1[10][50] = {"Grapes", "Watermelon"};
    char arr2[10][50] = {"Banana", "Strawberry", "Lemon"};
    char arr3[10][50];

    int N1 = 2, N2 = 3;

    // printf("Enter the number of elements for arr1: ");
    // scanf("%d", &N1);
    // if (N1 < 3) {
    //     printf("Value must be 3 or more!!");
    //     sleep(3);
    //     main();
    // }

    // printf("Enter the number of elements for arr2:");
    // scanf("%d", &N2);
    // if (N2 < 3) {
    //     printf("Value must be 3 or more!!");
    //     sleep(3);
    //     main();
    // }

    int count1 = 0;
    int count2 = 0;
    int count3 = 0;

    while ((count1 <= N1) || (count2 <= N2)) {
        if (count1 > N1) {
            Arr2(arr3, arr2, count2, count3);
        } else {
            if (count2 > N2) {
                Arr1(arr3, arr1, count1, count3);
            } else {
                if (strcmp(arr1[count1], arr2[count2]) < 0) {
                    Arr1(arr3, arr1, count1, count3);
                } else {
                    Arr2(arr3, arr2, count2, count3);
                }
            }
        }
        count3++;
    }

    printf("%s", arr3[1][1]);

    // for (int i = 0; i < 5; i++) {
    //     printf("%s\n", arr3[i]);
    // }
}