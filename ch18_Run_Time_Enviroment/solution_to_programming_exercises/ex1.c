// main.c
#include <stdio.h>

extern int sum_three(int a, int b, int c); // Declare the assembly function

int main() {
    int result = sum_three(10, 20, 30);
    printf("Sum = %d\n", result);
    return 0;
}

