char *find_char(const char *source, const char *chars) {
    // Check if either input pointer is NULL (doesn't point to a valid string),
    // or if either string is empty (first character is the null terminator '\0')
    if (!source || !chars || *source == '\0' || *chars == '\0') {
        return NULL;  // Return NULL if inputs are invalid or empty
    }

    // Create a pointer to walk through the source string (doesn't change the original pointer)
    const char *src_ptr = source;

    // Loop through each character in the source string
    while (*src_ptr != '\0') {  // Keep looping until the end of the source string (marked by '\0')

        // Create a pointer to walk through the chars string for each character in source
        const char *char_ptr = chars;

        // Loop through each character in the chars string
        while (*char_ptr != '\0') {  // Keep looping until the end of chars string

            // Compare the current character from source with the current character from chars
            if (*src_ptr == *char_ptr) {
                // If they match, return a pointer to that character in the source string
                // (casting to non-const because the function returns a non-const pointer)
                return (char *)src_ptr;
            }

            // Move the char_ptr to the next character in chars
            char_ptr++;
        }

        // Move the src_ptr to the next character in source
        src_ptr++;
    }

    // If no match was found after checking all characters, return NULL
    return NULL;
}

