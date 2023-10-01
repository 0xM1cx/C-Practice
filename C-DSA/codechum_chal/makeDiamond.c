#include <stdio.h>

void main() {
    int addInt;
    printf("Enter an odd integer: ");
    scanf(" %d", &addInt);

    if (addInt % 2 == 0) {
        printf("it must be an odd\n\n\n");
        main();
    }

    int space = addInt / 2;
    for (int i = 1; i <= addInt; i += 2) {
        for (int j = 1; j <= space; j++) {
            printf(" ");
        }
        for (int b = 1; b <= i; b++) {
            printf("*");
        }
        printf("\n");
        space--;
    }

    space = 1;
    for (int i = addInt - 2; i >= 1; i -= 2) {
        for (int j = 1; j <= space; j++) {
            printf(" ");
        }
        for (int b = 1; b <= i; b++) {
            printf("*");
        }
        printf("\n");
        space++;
    }
}