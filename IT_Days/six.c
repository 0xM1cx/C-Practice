#include <stdio.h>

void main() {
    int x;
    scanf("%d", &x);
    int cunter = 0;
    for (int i = 2; i < x; i++) {
        if (i % 2 != 0) {
            cunter++;
        }
    }

    printf("Output: %d", cunter);
}