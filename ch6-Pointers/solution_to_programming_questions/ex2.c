int del_substr(char *str, const char *substr) {
    // Check for NULL pointers or empty substring
    if (!str || !substr || *substr == '\0') {
        return 0;  // nothing to remove
    }

    char *start = str;  // pointer to walk through 'str'

    // Search for the first occurrence of 'substr' in 'str'
    while (*start != '\0') {
        char *s1 = start;            // pointer in str
        const char *s2 = substr;     // pointer in substr

        // Compare characters in str and substr
        while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2) {
            s1++;    // advance through str
            s2++;    // advance through substr
        }

        // If we reached the end of substr, we found a match
        if (*s2 == '\0') {
            // s1 is now pointing just after the matched part in str
            // We copy from s1 back to start (overwrite the match)

            while (*s1 != '\0') {
                *start = *s1;  // overwrite matched part with following chars
                start++;
                s1++;
            }

            *start = '\0';  // add null terminator to end the new string
            return 1;       // successful deletion
        }

        start++;  // move to the next character in str and try again
    }

    // If we get here, no match was found
    return 0;
}

