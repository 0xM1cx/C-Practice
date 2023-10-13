#include <stdio.h>

int main() {
    int N;
    printf("Enter the number of elements: ");
    scanf("%d", &N);
    if (N == 0) {
        printf("Sum of elements: 0");
        return 1;
    }

    int sum = 0;
    int arr[N];
    if (N > 1) {
        printf("Enter the elements: \n");
    } else {
        printf("Enter the elements: ");
    }

    for (int i = 0; i < N; i++) {
        int el;
        scanf("%d", &el);
        arr[i] = el;
    }

    for (int b = 0; b < N; b++) {
        sum += arr[b];
    }

    printf("Sum of elements: %d", sum);
    return 0;
}