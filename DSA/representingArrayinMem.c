#include <stdio.h>

int main() {
    // int arr[5] = {1, 2, 3, 4, 5};
    // for (int b = 0; b < sizeof(arr) / sizeof(arr[0]); b++) {
    //     printf("%x\n", &arr[b]);
    // }

    // int *start = &arr[0];
    // size_t k = sizeof(arr[1]);
    // printf("\n\n %x", start + 2);
    // int i = 2;
    // int s = (k * (i - 1));
    // int *loc = (start + s);
    // printf("\n\n=====================\n\n");
    // printf("%x", start + s);

    int arr[] = {10, 20, 30, 40, 50};
    // ine na loop para makita ta an respective addresses nira in memory
    for (int b = 0; b < sizeof(arr) / sizeof(arr[0]); b++) {
        printf("%p\n", &arr[b]);
    }

    int k = sizeof(int); // Amot size han kada interger, kemi kemi la ine. pwede ko manla ig surat 4
    // amo man usually size an in 4 bytes
    int i = 3; // Index han element na we want to access

    // pormula
    int *element_address = (int *)((char *)arr + (k * i));

    printf("Address of arr[%d]: %p\n", i, (void *)element_address);
    printf("Value at arr[%d]: %d\n", i, *element_address);

    return 0;
}