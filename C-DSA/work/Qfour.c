#include <stdio.h>

int main() {
    char input;
    printf("INPUT: ");
    scanf(" %c", &input);

    if (input == 'm' || input == 'M') {
        printf("\nHello Sir");
    } else if (input == 'f' || input == 'F') {
        printf("Hello Madam");
    } else {
        main();
    }
    return 0;
}
