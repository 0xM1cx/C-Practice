#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool isPalindrom(char *s) {
    int n = strlen(s);
    for (int i = 0, j = n - 1; i < j; ++i, --j) {
        if (s[i] != s[j]) {
            return false;
        }
    }
    return true;
}

const char *strbool(bool n) {
    return n ? "True" : "False";
}

int main() {
    char x[1000];
    scanf("%[^\n]s", x);

    const char *ptr = strbool(isPalindrom(x));
    printf("%s", ptr);
    return 0;
}