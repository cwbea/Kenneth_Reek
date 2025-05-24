#include <stdio.h>      // For printf and perror
#include <stdlib.h>     // For atoi and EXIT codes
#include <time.h>       // For struct tm, mktime

int main(int argc, char *argv[]) {
    // Check if user provided exactly 3 command-line arguments (month, day, year)
    if (argc != 4) {
        // Print usage message if incorrect number of arguments is provided
        printf("Usage: %s <month> <day> <year>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Convert command-line arguments from strings to integers
    int month = atoi(argv[1]);  // Convert first argument to month
    int day = atoi(argv[2]);    // Convert second argument to day
    int year = atoi(argv[3]);   // Convert third argument to year

    // Prepare a struct tm to hold the broken-down time
    struct tm date = {0};   // Initialize all fields to zero

    // Fill the struct with user-provided date
    date.tm_mday = day;         // Day of the month (1–31)
    date.tm_mon = month - 1;    // Month (0–11). Subtract 1 since Jan = 0 in struct tm
    date.tm_year = year - 1900; // Years since 1900. So 2025 -> 125

    // Convert broken-down time to time_t (epoch seconds), which also normalizes it
    if (mktime(&date) == -1) {
        // mktime() failed to convert (invalid date)
        perror("Invalid date");
        return EXIT_FAILURE;
    }

    // Array of weekday names corresponding to tm_wday (0 = Sunday, 6 = Saturday)
    const char *weekday_names[] = {
        "Sunday", "Monday", "Tuesday", "Wednesday",
        "Thursday", "Friday", "Saturday"
    };

    // Print the result
    printf("The date %02d/%02d/%d falls on a %s.\n",
           month, day, year, weekday_names[date.tm_wday]);

    return EXIT_SUCCESS; // Program completed successfully
}

