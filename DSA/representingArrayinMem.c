#include <stdio.h>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int *start = &arr[0];
    // int s = (int)start;
    int k = sizeof(arr[1]);
    int i = 2;
    // printf("%d", *start);
    int loc = *start + k * (i - 1);
    printf("%x", start);
    return 0;
}