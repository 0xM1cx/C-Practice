#include <stdio.h>
#include <string.h>

int main() {
    char ans[4];
    int test = 0;
    printf("INPUT: ");
    scanf("%s", ans);
    if (!(strcmp(ans, "pass"))) {
        printf("Correct Password!!");
    } else {
        printf("HEHEHEHEHEH");
    }

    if (test) {
        printf("Welcome Root user");
        printf("%d", test);
    }
    return 0;
}