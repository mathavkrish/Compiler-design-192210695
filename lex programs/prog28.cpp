28:              #include <stdio.h>
#include <string.h>
#define MAX_INPUT_LENGTH 10
int main() {
    char s[MAX_INPUT_LENGTH];
    printf("Enter any operator: ");
    if (fgets(s, sizeof(s), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }
    size_t len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0';
    }
    if (strlen(s) > 2) {
        printf("Invalid operator.\n");
        return 1;
    }
    switch(s[0]) {
        case '>':
            if (s[1] == '=') {
                printf("Greater than or equal\n");
            } else {
                printf("Greater than\n");
            }
            break;
        case '<':
            if (s[1] == '=') {
                printf("Less than or equal\n");
            } else {
                printf("Less than\n");
            }
            break;
        case '=':
            if (s[1] == '=') {
                printf("Equal to\n");
            } else {
                printf("Assignment\n");
            }
            break;
        case '!':
            if (s[1] == '=') {
                printf("Not Equal\n");
            } else {
                printf("Bit Not\n");
            }
            break;
        case '&':
            if (s[1] == '&') {
                printf("Logical AND\n");
            } else {
                printf("Bitwise AND\n");
            }
            break;
        case '|':
            if (s[1] == '|') {
                printf("Logical OR\n");
            } else {
                printf("Bitwise OR\n");
            }
            break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
            printf("Arithmetic operator\n");
            break;
        default:
            printf("Not an operator\n");
    }

    return 0;
}
