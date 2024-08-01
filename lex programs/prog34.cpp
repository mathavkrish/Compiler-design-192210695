#include <stdio.h>
#include <string.h>

int main() {
    char string[50];
    int flag, count = 0;

    printf("The grammar is: S->aS, S->Sb, S->ab\n");
    printf("Enter the string to be checked:\n");

    // Use fgets instead of gets
    if (fgets(string, sizeof(string), stdin) != NULL) {
        // Remove the newline character if present
        size_t len = strlen(string);
        if (len > 0 && string[len - 1] == '\n') {
            string[len - 1] = '\0';
        }
    }

    if (string[0] == 'a') {
        flag = 0;
        for (count = 1; string[count - 1] != '\0'; count++) {
            if (string[count] == 'b') {
                flag = 1;
                continue;
            } else if ((flag == 1) && (string[count] == 'a')) {
                printf("The string does not belong to the specified grammar\n");
                break;
            } else if (string[count] == 'a') {
                continue;
            } else if ((flag == 1) && (string[count] == '\0')) {
                printf("String accepted…..!!!!\n");
                break;
            } else {
                printf("String not accepted\n");
            }
        }
    }

    return 0;
}

