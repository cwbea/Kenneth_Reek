#include <stdio.h>

int main() {
    int year, leap_year;

    // Read the year from user input
    printf("Enter a year: ");
    scanf("%d", &year);

    // Check if the year is a leap year
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        leap_year = 1;  // It's a leap year
    } else {
        leap_year = 0;  // It's not a leap year
    }

    // Output the result
    if (leap_year) {
        printf("%d is a leap year.\n", year);
    } else {
        printf("%d is not a leap year.\n", year);
    }

    return 0;
}

