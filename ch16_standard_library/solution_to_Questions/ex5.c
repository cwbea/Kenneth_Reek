/*   Problems in the Code:

    Misspelled function name:

        locatime → ❌ wrong spelling

       Correct: localtime

    Missing #include <stdio.h>:

        Needed for printf.

    Missing argument in time() call:

        time() expects a pointer to time_t or NULL.

        So time(NULL) should be used if you're not storing the result elsewhere.

    Missing comma at end of printf() format string:

        You're missing a comma between the format string and the first variable.

    Incorrect tm_year usage:

        tm_year is the number of years since 1900, so you need to add 1900.

    Month indexing is zero-based:

        tm_mon ranges from 0 (January) to 11 (December), so add 1.
*/

//corrected code 


#include <stdio.h>   // for printf
#include <time.h>    // for time, localtime, struct tm

int main() {
    struct tm *tm;       // pointer to time structure
    time_t now;          // holds current time in seconds

    now = time(NULL);    // get current time
    tm = localtime(&now); // convert to local time structure

    // Print time in military format: HH:MM:SS DD/MM/YYYY
    printf("%02d:%02d:%02d %02d/%02d/%04d\n",
           tm->tm_hour, tm->tm_min, tm->tm_sec,
           tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);

    return 0;
}

