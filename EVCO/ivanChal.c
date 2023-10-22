#include <stdio.h>
#include <string.h>
void main() {
    char name[100];
    printf("INPUT: ");
    fgets(name, sizeof(name), stdin);
    int count = 0;
    for (int i = 0; i < strlen(name); i++) {
        int flag = 0;
        for (int k = 0; k <= strlen(name); k++) {
            for (int j = count; j < k; j++) {
                printf("%c", name[j]);
            }
            if (flag < strlen(name)) {
                printf("\n");
                flag++;
            } else {
                break;
            }
        }
        count++;
    }
}