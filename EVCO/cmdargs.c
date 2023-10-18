#include <stdio.h>
#include <string.h>

void main(int argc, char *argv[]) {
    char *name = argv[1];

    strncat(name, argv[2], strlen(argv[2]));
    strncat(name, argv[3], strlen(argv[3]));

    printf("Hello my name is %s", name);
}