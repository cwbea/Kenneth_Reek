#include <stdio.h>     // This lets us use input/output functions like printf() and getchar()
#include <ctype.h>     // This allows us to use character classification functions like isdigit(), isspace(), etc.

int main(void) {
    int ch;                          // Variable to store each character read from input (as an int to hold EOF)
    unsigned long total = 0;         // Counter for total number of characters read

    // Counters for each character category
    unsigned long ctrl = 0;          // Number of control characters (like backspace, newline, etc.)
    unsigned long space = 0;         // Number of whitespace characters (space, tab, newline, etc.)
    unsigned long digit = 0;         // Number of digits (0–9)
    unsigned long lower = 0;         // Number of lowercase letters (a–z)
    unsigned long upper = 0;         // Number of uppercase letters (A–Z)
    unsigned long punct = 0;         // Number of punctuation characters (!, ., ?, etc.)
    unsigned long nonprint = 0;      // Number of non-printable characters (anything isprint() says is false)

    // Read characters from standard input one by one until EOF (End Of File)
    while ((ch = getchar()) != EOF) {
        total++;  // Count this character toward the total

        // Check and count each type of character using functions from <ctype.h>
        if (iscntrl(ch)) ctrl++;         // If it's a control character, increment ctrl
        if (isspace(ch)) space++;        // If it's a whitespace character, increment space
        if (isdigit(ch)) digit++;        // If it's a digit, increment digit
        if (islower(ch)) lower++;        // If it's a lowercase letter, increment lower
        if (isupper(ch)) upper++;        // If it's an uppercase letter, increment upper
        if (ispunct(ch)) punct++;        // If it's a punctuation mark, increment punct
        if (!isprint(ch)) nonprint++;    // If it's NOT a printable character, increment nonprint
    }

    // If no characters were entered, inform the user and end the program
    if (total == 0) {
        printf("No characters were read.\n");
        return 0;  // Exit the program early
    }

    // Show results: print percentages for each character category
    printf("Character category percentages (based on %lu characters):\n", total);
    printf("Control characters   : %.2f%%\n", 100.0 * ctrl / total);      // %.2f formats to 2 decimal places
    printf("Whitespace characters: %.2f%%\n", 100.0 * space / total);
    printf("Digits               : %.2f%%\n", 100.0 * digit / total);
    printf("Lowercase letters    : %.2f%%\n", 100.0 * lower / total);
    printf("Uppercase letters    : %.2f%%\n", 100.0 * upper / total);
    printf("Punctuation          : %.2f%%\n", 100.0 * punct / total);
    printf("Non-printable chars  : %.2f%%\n", 100.0 * nonprint / total);

    return 0;  // End of main function
}

