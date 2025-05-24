#include <stdio.h>
#include <string.h>

/*
 * Modified: Removed the 'size' parameter from the function.
 * This version relies on a NULL-terminated keyword table.
 */
int lookup_keyword(char const * const desired_word,
                   char const * const keyword_table[]) // Removed size
{
    char const * const *kwp;

    /*
     * Modified loop: Now iterates until a NULL is found,
     * instead of relying on a size parameter.
     */
    for (kwp = keyword_table; *kwp != NULL; kwp++)
        if (strcmp(desired_word, *kwp) == 0)
            return kwp - keyword_table; // Return the index if found

    return -1; // Not found
}

int main(void)
{
    /*
     * Modified keyword table: Added NULL at the end.
     * This replaces the need to track or pass the size of the array.
     */
    char const *keywords[] = { "auto", "break", "case", "char", NULL };

    char const *word = "case";
    int index = lookup_keyword(word, keywords);

    if (index >= 0)
        printf("Found '%s' at index %d.\n", word, index);
    else
        printf("'%s' not found in keyword table.\n", word);

    return 0;
}

