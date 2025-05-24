#include <stdio.h>

int main(void) {
    float a, b, c;

    printf("Enter three side lengths of a triangle:\n");
    scanf("%f %f %f", &a, &b, &c);

    // Check for valid triangle
    if (a <= 0 || b <= 0 || c <= 0) {
        printf("Side lengths must be positive numbers.\n");
    } else if (a + b <= c || a + c <= b || b + c <= a) {
        printf("These sides do not form a valid triangle.\n");
    } else {
        // Valid triangle — determine type
        if (a == b && b == c) {
            printf("The triangle is equilateral.\n");
        } else if (a == b || b == c || a == c) {
            printf("The triangle is isosceles.\n");
        } else {
            printf("The triangle is scalene.\n");
        }
    }

    return 0;
}

