#include <stdio.h>

int main() {
    char ans[4];
    int test;
    printf("INPUT: ");
    scanf("%s", ans);
    if (test == 1) {
        printf("Flag{Gwapo}");
    } else {
        printf("INCORRECT: %s", ans);
    }
    return 0;
}