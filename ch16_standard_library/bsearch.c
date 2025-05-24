/*
 * Demonstrates searching an array of structures using bsearch.
 * The array is first sorted using qsort, then we use bsearch to find a record by key.
 */

#include <stdlib.h>   // For qsort, bsearch, EXIT_SUCCESS
#include <string.h>   // For strcmp, strcpy
#include <stdio.h>    // For printf

// Define a structure called Record using typedef
typedef struct {
    char key[10];     // A short string key (used for sorting and searching)
    int other_data;   // Associated integer data
} Record;

/*
 * Comparison function used by both qsort and bsearch.
 * This function compares the 'key' field of two Record structures.
 *
 * Parameters:
 *   a - pointer to the first element (Record or key)
 *   b - pointer to the second element (Record)
 *
 * Returns:
 *   < 0 if a < b
 *     0 if a == b
 *   > 0 if a > b
 */
int r_compare(const void *a, const void *b) {
    // Cast void pointers to Record pointers, then compare the keys
    return strcmp(((const Record *)a)->key, ((const Record *)b)->key);
}

/*
 * Main function - program entry point
 */
int main() {
    Record array[50];  // Declare an array of 50 Record structures
    Record key;        // A Record used to store the search key
    Record *ans;       // A pointer that will point to the found element (or NULL)

    // ---- Fill the array with sample data ----
    for (int i = 0; i < 50; ++i) {
        // Generate keys like "key00", "key01", ..., "key49"
        sprintf(array[i].key, "key%02d", i);
        array[i].other_data = i * 100;  // Just example data
    }

    // ---- Sort the array before using bsearch ----
    // qsort needs:
    //   - pointer to the array
    //   - number of elements
    //   - size of each element
    //   - pointer to the comparison function
    qsort(array, 50, sizeof(Record), r_compare);

    // ---- Create a key to search for ----
    // We're searching for a record with key = "key25"
    strcpy(key.key, "key25");

    // ---- Perform binary search using bsearch ----
    // Parameters:
    //   &key       - pointer to the key we're searching for
    //   array      - pointer to the sorted array
    //   50         - number of elements in the array
    //   sizeof(Record) - size of each element
    //   r_compare  - comparison function to compare keys
    ans = bsearch(&key, array, 50, sizeof(Record), r_compare);

    // ---- Check the result of the search ----
    if (ans != NULL) {
        // If ans is not NULL, a match was found
        printf("Found record: Key = %s, Other Data = %d\n", ans->key, ans->other_data);
    } else {
        // If ans is NULL, no match was found
        printf("Record with key '%s' not found.\n", key.key);
    }

    return EXIT_SUCCESS;  // Return 0 to indicate successful execution
}

