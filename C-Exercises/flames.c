#include <ctype.h>
#include <stdio.h>
#include <string.h>

void remove_duplicates(char *name1, char *name2) {
    int i, j, len1 = strlen(name1), len2 = strlen(name2);

    for (i = 0; i < len1; i++) {
        for (j = 0; j < len2; j++) {
            if (tolower(name1[i]) == tolower(name2[j])) {
                name1[i] = ' ';
                name2[j] = ' ';
                break;
            }
        }
    }
}

int count_unique_chars(char *name) {
    int count = 0, i, j;
    char visited[strlen(name)]; // Array to store visited characters

    for (i = 0; i < strlen(name); i++) {
        visited[i] = 0;
    }

    for (i = 0; name[i] != '\0'; i++) {
        if (isalpha(name[i]) && !visited[i]) { // Check for alphabetic and not visited
            count++;
            visited[i] = 1;
            for (j = i + 1; name[j] != '\0'; j++) {
                if (tolower(name[i]) == tolower(name[j])) {
                    visited[j] = 1;
                }
            }
        }
    }

    return count;
}

char *get_flames_result(char *name) {
    int count = count_unique_chars(name);

    switch (count % 6) {
    case 0:
        return "Friends";
    case 1:
        return "Lovers";
    case 2:
        return "Affectionate";
    case 3:
        return "Married";
    case 4:
        return "Enemies";
    case 5:
        return "Siblings";
    }

    return NULL;
}

int main() {
    char name1[100], name2[100];
    int has_invalid_chars = 0; // Flag to indicate presence of non-letters

    printf("Enter first name: ");
    fgets(name1, sizeof(name1), stdin);

    // Remove trailing newline manually
    int len = strlen(name1);
    if (len > 0 && name1[len - 1] == '\n') {
        name1[len - 1] = '\0';
    }

    // Check for non-alphabetic characters
    for (int i = 0; name1[i] != '\0'; i++) {
        if (!isalpha(name1[i])) {
            has_invalid_chars = 1;
            break;
        }
    }

    if (has_invalid_chars) {
        printf("Error: Names cannot contain numbers or special characters. Please enter a valid name.\n");
    } else {
        printf("Enter second name: ");
        fgets(name2, sizeof(name2), stdin);

        // Remove trailing newline manually
        len = strlen(name2);
        if (len > 0 && name2[len - 1] == '\n') {
            name2[len - 1] = '\0';
        }

        // Check for non-alphabetic characters
        for (int i = 0; name2[i] != '\0'; i++) {
            if (!isalpha(name2[i])) {
                has_invalid_chars = 1;
                break;
            }
        }

        if (has_invalid_chars) {
            printf("Error: Names cannot contain numbers or special characters. Please enter a valid name.\n");
        } else {
            remove_duplicates(name1, name2);
            char *flames_result = get_flames_result(name1);
            printf("FLAMES result: %s\n", flames_result);
        }
    }

    return 0;
}
