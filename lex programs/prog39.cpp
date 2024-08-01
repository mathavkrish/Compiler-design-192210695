#include <stdio.h>

int main() {
    int x = 5;
    int y = 10;
    int z = 3;
    int result1, result2;

    // Calculate common subexpression once
    int common_subexpression = x * y;

    // Use the common subexpression
    result1 = common_subexpression + common_subexpression - (z * z);
    result2 = common_subexpression + common_subexpression + (y * z);

    // Print results
    printf("Result1: %d\n", result1);
    printf("Result2: %d\n", result2);

    return 0;
}
