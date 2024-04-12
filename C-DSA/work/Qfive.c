#include <stdio.h>

int main() {
    int input;
    printf("INPUT: ");
    scanf("%d", &input);

    if (input < 18) {
        printf("You are a minor");
    } else {
        printf("You are an adult");
    }
    return 0;
}
