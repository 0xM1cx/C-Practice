#include <stdio.h>

int convertToint(char c) {
    switch (c) {
    case 'I':
        return 1;
    case 'V':
        return 5;
    case 'X':
        return 10;
    case 'L':
        return 50;
    case 'C':
        return 100;
    case 'D':
        return 500;
    case 'M':
        return 1000;
    }
}

void main() {
    char s[1000];
    char *i = s;
    scanf("%[^\n]s", s);
    int temp = 0;
    int res = 0;
    while (*i != '\0') {
        temp = convertToint(*i);
        if (convertToint(*i) < convertToint(*(i + 1))) {
            temp = -temp;
        }
        res += temp;
        ++i;
    }

    printf("OUTPUT: %d", res);
}