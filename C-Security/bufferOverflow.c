#include <stdio.h>
#include <string.h>

int main() {
    char ans[4];
    int test = 0;
    int flag = 0;
    printf("INPUT: ");
    scanf("%s", ans);
    if (test != 0) {
        printf("Buffer Overflowed\n");
        flag = 1;
    } else {
        printf("Try Again");
    }

    if (flag == 1) {
        printf("Welcome Root user:  ");
    }
    return 0;
}
