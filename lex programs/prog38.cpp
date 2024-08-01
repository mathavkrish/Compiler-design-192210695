#include <stdio.h>
#include <ctype.h>

int main() {
    int c; // Current character
    int characters = 0; // Count of characters
    int words = 0; // Count of words
    int lines = 0; // Count of lines
    int in_word = 0; // Flag to track if we are in a word

    while ((c = getchar()) != EOF) {
        characters++; // Count every character

        if (c == '\n') {
            lines++; // Increment line count on newline
        }

        if (isspace(c) || ispunct(c)) {
            // End of a word if whitespace or punctuation is encountered
            if (in_word) {
                words++;
                in_word = 0;
            }
        } else {
            // We are in a word
            in_word = 1;
        }
    }

    // If the last character was part of a word, count it
    if (in_word) {
        words++;
    }

    // Print the counts
    printf("Characters: %d\n", characters);
    printf("Words: %d\n", words);
    printf("Lines: %d\n", lines);

    return 0;
}
