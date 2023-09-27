#include <stdio.h>

int main() {
    char arr1[10][100] = {"Belle", "Rae", "Ash", "Lil'o", "Ash"};
    char myname[100] = {"Belle",
                        "Rae",
                        "Ash",
                        "Lil'o",
                        "Ash"};
    int len = sizeof(arr1) / sizeof(arr1[0]);
    printf("%d", len);
    printf("\n%s", myname);
    return 0;
}