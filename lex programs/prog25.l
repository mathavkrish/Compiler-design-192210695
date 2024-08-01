%{
#include <stdio.h>
#include <string.h>

int count = 0;
%}

%%
"hi"    { count++; }
[ \t\n]+   /* Skip whitespace */
.          /* Ignore other characters */
%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter a sentence: ");
    yylex();
    printf("The word '%s' occurred %d times.\n","hi", count);
    return 0;
}
