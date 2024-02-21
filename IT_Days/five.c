#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct words {
    char usaKaWord[100];
};
void main() {
    char *s = malloc(100 * sizeof(char));
    scanf("%[^\n]s", s);

    struct words w[10];
    char *temp = malloc(50 * sizeof(char));
    int counter = 0;

    while (*s != '\0') {
        if (*s == ' ') {
            w[counter].usaKaWord = *temp;
            counter++;
        } else {
        }

        ++s;
    }
}