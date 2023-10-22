#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

int main() {
    char passcmp[MAX];
    char pass[MAX];
    char user[MAX];

start:
    printf("Create your Username: ");
    fgets(user, sizeof(user), stdin);

    printf("Create your Password: ");
    fgets(pass, sizeof(pass), stdin);

    system("cls");

    printf("welcome %s \n", user);
    printf("Please enter your Password: ");
    fgets(passcmp, sizeof(passcmp), stdin);

    if (strcmp(pass, passcmp) == 0) {
        printf("Login Succesfull, welcome %c", user[MAX]);
    } else {
        goto start;
    }
    return 0;
}