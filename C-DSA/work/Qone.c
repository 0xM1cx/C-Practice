#include <stdio.h>

int main() {
    int numbers[5];
    int biggest = 0;
    printf("Numbers: \n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &numbers[i]);
        if (numbers[i] > biggest) {
            biggest = numbers[i];
        }
    }
    printf("The biggest number is: %d", biggest);
}