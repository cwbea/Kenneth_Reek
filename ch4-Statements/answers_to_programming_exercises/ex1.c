#include <stdio.h>
#include <math.h>

int main(void) {
    double n, approx = 1.0, next;
    
    printf("Enter a positive number: ");
    scanf("%lf", &n);

    if (n <= 0) {
        printf("Input must be a positive number.\n");
        return 1;
    }

    int step = 0;
    do {
        next = (approx + n / approx) / 2.0;
        printf("Step %d: %.15f\n", step, approx);
        if (next == approx) break;
        approx = next;
        step++;
    } while (1);

    printf("\nFinal approximation of sqrt(%.2f) is %.15f\n", n, approx);
    printf("Actual sqrt using math.h: %.15f\n", sqrt(n));

    return 0;
}

