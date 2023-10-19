#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    int n;
    scanf("%d", &n);
    // Complete the code to print the pattern.
    for (int i = n; i > 0; i--) {
        for (int j = n; j > 0; j--) {
            printf("%d ", i);
        }
        printf("\n");
    }

    return 0;
}