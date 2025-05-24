#include <stdio.h>      // For printf to print text to the screen
#include <time.h>       // For time-related functions like time() and localtime()

int main() {
    // Declare a variable of type time_t to hold the current calendar time (in seconds since 1970)
    time_t now;

    // Declare a pointer to struct tm which will store the local time broken into components
    struct tm *tm_info;

    // Get the current time in seconds and store it in 'now'
    now = time(NULL);  // time(NULL) returns the current time

    // Convert 'now' into local time (hour, minute, second, etc.) and store the result in tm_info
    tm_info = localtime(&now);

    // Access the hour and minute from the struct tm
    int hour = tm_info->tm_hour;   // tm_hour is the hour in 24-hour format (0–23)
    int minute = tm_info->tm_min;  // tm_min is the minute (0–59)

    // Convert the 24-hour format to 12-hour format so it sounds more familiar
    int twelve_hour = hour % 12;        // e.g. 13 becomes 1 PM, 0 becomes 12
    if (twelve_hour == 0) twelve_hour = 12;  // handle 0 as 12 (midnight or noon)

    // Print the "child-like" version of the current time
    // Example: "The big hand is on the 45 and the little hand is on the 2"
    printf("The big hand is on the %d and the little hand is on the %d.\n", 
           minute, twelve_hour);

    return 0;  // Return 0 to indicate the program ran successfully
}

