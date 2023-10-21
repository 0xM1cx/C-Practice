#include <stdio.h>

void main() {
    int size;
    printf("Enter size of array: ");
    scanf("%d", &size);

    int arr[size];
    int nodup[50];
    printf("Enter elements in array: \n");
    for (int i = 0; i < size; i++) {
        int element;
        scanf("%d", &element);
        arr[i] = element;
    }

    // for (int j = 0; j < size; j++) {
    //     for (int n = j + 1; n < size;) {
    //         if (arr[j] == arr[n]) {
    //             for (int m = j; m < size; m++) {
    //                 arr[m] = arr[m + 1];
    //             }
    //             size--;
    //         } else {
    //             n++;
    //         }
    //     }
    // }
    int count = 0;
    for (int h = 0; h < size; h++) {
        int flag = 0;
        for (int u = h + 1; u < size; u++) {
            if (arr[h] == arr[u]) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            nodup[count] = arr[h];
            count++;
        }
    }

    printf("Array after removing duplicates: ");
    for (int h = 0; h < count; h++) {
        printf("%d ", nodup[h]);
    }
}