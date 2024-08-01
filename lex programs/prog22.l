%{
#include <stdio.h>
%}

%%
\"//\".* { /* Single-line comment */ }
\"/\" { / Multi-line comment start */
    while (1) {
        char ch = input();
        if (ch == EOF) break;
        if (ch == '*' && input() == '/') break;
    }
}
. ; /* Ignore other characters */
%%

int yywrap() {
    return 1;
}

int main(int argc, char* argv[]) {
    yyin = fopen("input.c", "r"); // Open input file
    yyout = fopen("output.c", "w"); // Open output file

    yylex(); // Perform lexical analysis

    fclose(yyin);
    fclose(yyout);
    return 0;
}