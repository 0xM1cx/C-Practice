#include <stdio.h>
#include <string.h>


int main() {
    char ans[4];
    int flag = 0;
    int test = 0;
    printf("INPUT: ");
    scanf("%s", ans);
    if (test != 0) {
        printf("Buffer Overflowed\n");
    } else {
        printf("Try Again");
    }

    if (flag == 1) {
        printf("Welcome Root user\n");
    }
    return 0;
}
