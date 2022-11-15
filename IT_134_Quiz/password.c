#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void main(){
    char pass[100];
    printf("Password: ");
    scanf("%s", pass);

    int len = strlen(pass);
    printf("\n Your Hidden Password: ");
    for(int i = 1; i <= len; i++){
        printf("*");
    }
}