#include <stdio.h>

int main() {
    int x, y, a, b;

    // Read values for x, y, a, and b
    printf("Enter values for x, y, a, and b: ");
    scanf("%d %d %d %d", &x, &y, &a, &b);

    // Check if x is less than y
    if (x < y) {
        printf("WRONG\n");
    }

    // Check if a is greater than or equal to b
    else if (a >= b) {
        printf("WRONG\n");
    }
    // If both conditions are false, print RIGHT
    else {
        printf("RIGHT\n");
    }

    return 0;
}

