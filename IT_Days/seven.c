#include <stdio.h>
#include <string.h>

void main() {
    char x[231];
    scanf("%s", x);
    int n = strlen(x);

    if (x[0] == '-') {
        char b[100];
        for (int i = 1; i < strlen(x); i++) {
            b[i - 1] = x[i];
        }

        char *rev = strrev(b);
        int n = strlen(rev);
        for (int i = 0; i < n; i++) {
            if (rev[i] != '0') {
                printf("-%c", rev[i]);
            }
        }

    } else {

        char *rev = strrev(x);
        int n = strlen(rev);
        for (int i = 0; i < n; i++) {
            if (rev[i] != '0') {
                printf("%c", rev[i]);
            }
        }
    }
}