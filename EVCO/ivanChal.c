#include <stdio.h>
#include <string.h>
void main() {
    char name[100];
    printf("INPUT: ");
    fgets(name, sizeof(name), stdin);
    int count = 0;
    for (int i = 0; i < strlen(name); i++) {
        for (int k = 0; k < strlen(name); k++) {
            for (int j = count; j < k; j++) {
                printf("%c", name[j]);
            }
            printf("\n");
        }
        count++;
    }
}