#include <stdio.h>
#include <string.h>

void main() {
    char x[1000];
    scanf("%[^\n]s", x);

    char *rev = strrev(x);

    int counter = 0;
    while (*rev != ' ') {
        ++counter;
        ++rev;
    }

    printf("Adi it outpu: %d", counter);
}