#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isValidIdentifier(const char *string);

int main() {
    char string[50];
    printf("Enter the string: ");
    fgets(string, sizeof(string), stdin);
    size_t len = strlen(string);
    if (len > 0 && string[len - 1] == '\n') {
        string[len - 1] = '\0';
    }

    if (isValidIdentifier(string)) {
        printf("Input string is a valid identifier\n");
    } else {
        printf("Input string is not a valid identifier\n");
    }

    return 0;
}

int isValidIdentifier(const char *string) {
    if (strlen(string) == 0) {
        return 0;
    }
    if (!isalpha(string[0]) && string[0] != '_' && string[0] != '$') {
        return 0;
    }
    for (size_t i = 1; i < strlen(string); i++) {
        if (!isalnum(string[i]) && string[i] != '_') {
            return 0;
        }
    }
    return 1;
}
