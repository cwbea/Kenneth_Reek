/*
 * Demonstrates sorting an array of structures using qsort.
 * We will sort based on a string field called `key` inside a struct.
 */

#include <stdlib.h>   // For qsort and EXIT_SUCCESS
#include <string.h>   // For strcmp (string comparison)
#include <stdio.h>
/*
 * Define a structure type called 'Record' using typedef.
 * This makes 'Record' a new type name for the structure.
 */
typedef struct {
    char key[10];     // Key used for sorting, max 9 chars + null terminator
    int other_data;   // Additional data associated with the key
} Record;

/*
 * Comparison function for qsort.
 * This function will compare the 'key' fields of two Record structs.
 *
 * Parameters:
 *   a - a pointer to the first Record element
 *   b - a pointer to the second Record element
 *
 * Returns:
 *   Negative if a < b, zero if equal, positive if a > b (based on strcmp)
 */
int r_compare(const void *a, const void *b) {
    // Cast void pointers to Record pointers, then compare their keys
    return strcmp(((const Record *)a)->key, ((const Record *)b)->key);
}

/*
 * Main function - entry point of the program
 */
int main() {
    Record array[50];  // Declare an array of 50 Records

    // ---- Fill the array with sample data (for demo purposes) ----
    for (int i = 0; i < 50; ++i) {
        // Generate sample keys like "key49", "key48", ..., "key0"
        sprintf(array[i].key, "key%02d", 49 - i);  // Put key strings in reverse order
        array[i].other_data = i * 10;              // Fill other_data with multiples of 10
    }

    // ---- Sort the array by the 'key' field using qsort ----
    // Parameters:
    //   array      - pointer to the first element of the array
    //   50         - number of elements in the array
    //   sizeof(Record) - size of each element
    //   r_compare  - comparison function to sort based on key
    qsort(array, 50, sizeof(Record), r_compare);

    // ---- Print the sorted array to verify the result ----
    for (int i = 0; i < 50; ++i) {
        printf("Key: %s, Other Data: %d\n", array[i].key, array[i].other_data);
    }

    return EXIT_SUCCESS; // Return 0 to indicate successful execution
}

