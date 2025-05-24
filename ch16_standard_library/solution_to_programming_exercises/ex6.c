#include <stdio.h>     // for printf
#include <math.h>      // for pow() function to handle exponents

// Function to compute the monthly loan payment
double payment(double amount, double interest, int years) {
    // Convert annual interest percentage to monthly decimal rate
    double monthly_rate = (interest / 100.0) / 12.0;

    // Total number of monthly payments over the loan duration
    int total_months = years * 12;

    // Use the loan payment formula:
    // payment = (amount * monthly_rate) / (1 - pow(1 + monthly_rate, -total_months))
    double monthly_payment = (amount * monthly_rate) /
                              (1 - pow(1 + monthly_rate, -total_months));

    // Return the monthly payment
    return monthly_payment;
}

int main() {
    // Example usage
    double loan_amount = 100000;    // Amount of the loan in dollars
    double annual_interest = 8.0;   // Annual interest rate in percent
    int loan_years = 20;            // Duration of the loan in years

    // Call the function to calculate the monthly payment
    double result = payment(loan_amount, annual_interest, loan_years);

    // Print the result rounded to 2 decimal places
    printf("Monthly payment: $%.2f\n", result);  // Expected: $836.44

    return 0;
}

