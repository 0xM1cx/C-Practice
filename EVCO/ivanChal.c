#include <stdio.h>
#include <string.h>
void main() {
    char name[100];
    printf("INPUT: ");
    fgets(name, sizeof(name), stdin);
    int ctr = 0;
    int flag = 0;
    for (int i = 0; i < strlen(name); i++) {
        for (int j = i; j < strlen(name); j++) {
            for (int k = ctr; k < j; k++) {
                printf("%c ", name[k]);
            }
            printf("\n");
        }
        ctr++;
    }
}