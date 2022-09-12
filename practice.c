#include <stdio.h>


int main()
{
    char name[100];
    char otherName[100];
    printf("What is your name? \n");
    scanf("%s", name, otherName);

    printf("Hello , %s + %s", name, otherName);
}
