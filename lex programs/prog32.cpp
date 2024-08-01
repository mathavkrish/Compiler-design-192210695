#include <stdio.h>
#include <string.h>

int main() {
    char gram[100], part1[50], part2[50], modifiedGram[50], newGram[50];
    int i, j = 0, k = 0, l = 0, pos;
    printf("Enter Production (A->): ");
    fgets(gram, sizeof(gram), stdin);
    size_t len = strlen(gram);
    if (len > 0 && gram[len - 1] == '\n') {
        gram[len - 1] = '\0';
    }
    for (i = 0; gram[i] != '|' && gram[i] != '\0'; i++, j++) {
        part1[j] = gram[i];
    }
    part1[j] = '\0';
    
    j = 0;
    if (gram[i] != '\0') {
        for (i = i + 1; gram[i] != '\0'; i++, j++) {
            part2[j] = gram[i];
        }
    }
    part2[j] = '\0';
    for (i = 0; i < strlen(part1) && i < strlen(part2); i++) {
        if (part1[i] == part2[i]) {
            modifiedGram[k++] = part1[i];
            pos = i + 1;
        } else {
            break;
        }
    }
    modifiedGram[k] = 'X';
    modifiedGram[k + 1] = '\0';
    for (i = pos, j = 0; part1[i] != '\0'; i++, j++) {
        newGram[j] = part1[i];
    }
    newGram[j++] = '|';
    for (i = pos; part2[i] != '\0'; i++, j++) {
        newGram[j] = part2[i];
    }
    newGram[j] = '\0';
    printf("\nA -> %s\n", modifiedGram);
    printf("X -> %s\n", newGram);
    
    return 0;
}
