#include <stdio.h>
#include <stdlib.h> // for system("cls");
int main() {
    system("cls");
    int userAge;
    printf("\n\nTo check age  just input a number, to exit just type n; to continue type y\n");
    printf("How old are you: ");
    scanf("%d", &userAge);
    int flag = 1;
    char choice;

    (userAge >= 18 && userAge >= 0) ? printf("Adult") : printf("Minor"); // checks if the user age is 18 above for adult and 17 upto 0 for minor. NO NEGATIVE age
    printf("\n\nCONTINUE? ");
    scanf(" %c", &choice);
    if (choice == 'y') {
        main();
    } else if (choice == 'n') {
        printf("\nGOODBYE!!");
        exit(0);
    }

    return 0;
}