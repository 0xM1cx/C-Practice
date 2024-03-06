#include <stdio.h>
#include <string.h>

void revStr(char s[]) {
    int n = strlen(s);
    int end = n - 1;
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == ' ' || i == 0) {

            for (int start = i; start <= end; ++start) {
                if (s[start] != ' ') {
                    printf("%c", s[start]);
                }
            }
            printf(" ");
            end = i;
        }
    }
}

int main() {
    char str[104];
    char new[104];

    scanf("%[^\n]s", str);
    int n = strlen(str) - 1;
    for (int i = n; i >= 0; --i) {
        if (str[i] == ' ') {
            str[i] = '\0';
        } else {
            break;
        }

        revStr(str);
    }
}