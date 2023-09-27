#include <stdio.h>

int main() {
    char arr1[][100] = {"Belle", "Rae", "Ash", "Lil'o", "Ash"};
    char *names[] = {"Belle", "Rae", "Ash", "Lil'o", "Ash"};
    char *myname = "Shawn";
    int len = sizeof(arr1) / sizeof(arr1[0]);

    printf("%d", len);
    printf("\n%s", myname);
    return 0;
}