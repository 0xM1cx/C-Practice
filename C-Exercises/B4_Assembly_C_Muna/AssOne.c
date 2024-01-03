#include <stdio.h>
#include <string.h>

void main(int argc, char *argv[]) {
    size_t len_one = strlen(argv[1]);
    size_t len_two = strlen(argv[2]);

    char nameOne[len_one];
    char nameTwo[len_two];

    strcpy(nameOne, argv[1]);
    strcpy(nameTwo, argv[2]);

    printf("Hello my name is %s %s\n", nameOne, nameTwo);
}