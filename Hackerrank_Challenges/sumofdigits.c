#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char string[100];
    int n;
    scanf("%d", &n);
    sprintf(string, "%d", n);

    int sum = 0;
    for (int i = 0; i < strlen(string); i++) {
        sum += string[i] - '0';
        printf("%d\n", string[i] - '0');
    }

    printf("\n\n%d", sum);

    return 0;
}