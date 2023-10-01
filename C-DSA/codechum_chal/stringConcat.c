#include <stdio.h>
#include <string.h>

void main() {
    char word1[100], word2[100];
    printf("Enter the first string: ");
    fgets(word1, sizeof(word1), stdin);

    printf("Enter the second string: ");
    fgets(word2, sizeof(word2), stdin);

    size_t lenOne = strlen(word1);
    size_t lenTwo = strlen(word2);

    word1[lenOne - 1] = '\0';
    word2[lenTwo - 1] = '\0';

    printf("Concatenated String: %s%s", word1, word2);
}
