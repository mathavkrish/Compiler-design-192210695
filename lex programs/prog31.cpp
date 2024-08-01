#include <stdio.h>
#include <string.h>

int main() {
    char a[10], A, B, alpha[50], temp[2];
    char s1[10], s2[10];
    int i, n, j, ind2 = 0, k = 0;
    
    printf("Enter the grammar: ");
    scanf("%s", a);
    
    A = a[0];
    
    if (a[0] == a[3]) {
        // Find the position of '|'
        for (i = 0; a[i]; i++) {
            if (a[i] == '|')
                ind2 = i;
        }
        
        if (ind2 == 0) {
            printf("Invalid grammar...\n");
        } else {
            B = a[ind2 + 1];
            
            // Extract parts of the grammar
            for (i = 0; a[i]; i++) {
                if (i > 3 && i < ind2) {
                    alpha[k] = a[i];
                    k++;
                } else if (i < 3) {
                    s1[i] = a[i];
                    s2[i] = a[i];
                }
            }
            
            // Add new parts to s1 and s2
            j = 3;
            for (i = 0; i < k; i++) {
                s2[j] = alpha[i];
                j++;
            }
            s1[3] = B;
            s1[4] = A;
            s1[5] = '`';
            s2[j] = A;
            s2[j + 1] = '`';
            s2[j + 2] = '|';
            s2[j + 3] = 'e';
            
            // Print s1
            for (i = 0; s1[i]; i++)
                printf("%c", s1[i]);
            printf("\n");
            printf("%c'", s2[0]);
            for (i = 1; s2[i]; i++)
                printf("%c", s2[i]);
        }
    } else {
        printf("There is no left recursion!\n");
    }
    
    return 0;
}
