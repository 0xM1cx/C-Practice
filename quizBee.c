#include <stdio.h>

void main(void) {
    for (int i = 0; i < 10; i++) {
        for (int b = 0; b < i; b++) {
            printf("*");
        }
        printf("\n");
    }
}