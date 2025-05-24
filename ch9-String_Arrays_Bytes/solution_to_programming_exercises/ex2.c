#include <stddef.h>  // Include for the size_t type, which is used to represent sizes and counts

// Function: my_strnlen
// Purpose: Safely calculate the length of a string that may not be null-terminated,
//          by checking up to 'maxlen' characters in the array.
size_t my_strnlen(const char *str, size_t maxlen) {
    size_t i = 0;  // 'i' is a counter to keep track of how many characters we've seen

    // Loop through the string:
    // Keep going while we haven't hit the max length AND the current character is not '\0'
    while (i < maxlen && str[i] != '\0') {
        i++;  // Move to the next character and count this one
    }

    // When we reach a null character or hit maxlen, return how many characters we counted
    return i;
}

