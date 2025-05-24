#include <stdio.h>

// Function to calculate the tax based on 1995 rules for single filers
float single_tax(float income) {
    if (income <= 23350.0f) {
        return 0.15f * income;
    } else if (income <= 56550.0f) {
        return 3502.50f + 0.28f * (income - 23350.0f);
    } else if (income <= 117950.0f) {
        return 12798.50f + 0.31f * (income - 56550.0f);
    } else if (income <= 256500.0f) {
        return 31832.50f + 0.36f * (income - 117950.0f);
    } else {
        return 81710.50f + 0.398f * (income - 256500.0f);
    }
}

// Optional: A main function to test the tax calculation
int main(void) {
    float income;
    printf("Enter your taxable income: ");
    scanf("%f", &income);
    printf("Your tax is: $%.2f\n", single_tax(income));
    return 0;
}

