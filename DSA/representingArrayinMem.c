#include <stdio.h>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};

    int *Base_Address = &arr[0];
    int i = 2;
    for (int b = 0; b < sizeof(arr) / sizeof(arr[0]); b++) {
        printf("%x\n", &arr[b]);
    }

    size_t k = sizeof(arr[2]);
    printf("\n\n%x", Base_Address + 2);

    int *loc = (Base_Address + k * (i - 0));
    printf("\n\n=====================\n\n");
    printf("%x", loc);

    // int arr[] = {10, 20, 30, 40, 50};
    // // ine na loop para makita ta an respective addresses nira in memory
    // for (int b = 0; b < sizeof(arr) / sizeof(arr[0]); b++) {
    //     printf("%p\n", &arr[b]);
    // }

    // int k = sizeof(int); // Amot size han kada interger, kemi kemi la ine. pwede ko manla ig surat 4
    // // amo man usually size an in 4 bytes
    // int i = 3; // Index han element na we want to access

    // // pormula
    // int *element_address = (int *)((char *)arr + (k * i));

    // printf("Address of arr[%d]: %p\n", i, (void *)element_address);
    // printf("Value at arr[%d]: %d\n", i, *element_address);

    return 0;
}