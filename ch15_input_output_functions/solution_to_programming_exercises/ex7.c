#include <stdio.h>    // For input/output functions
#include <stdlib.h>   // For exit(), malloc()
#include <string.h>   // For string handling functions

#define MAX_MEMBERS 10    // Max number of family members per family
#define MAX_FILENAME 100  // Max filename length

int main() {
    FILE *fp;                       // File pointer to open and read the input file
    int age;                        // Variable to store each age read
    int family[MAX_MEMBERS];       // Array to store ages of one family
    int count;                      // Number of members in current family
    float sum;                      // Sum of ages for calculating average
    char filename[MAX_FILENAME];   // Character array to store the input filename

    // Prompt the user to enter the filename
    printf("Enter the name of the file containing family ages: ");
    fgets(filename, sizeof(filename), stdin); // Read the filename from user input

    // Remove newline character from the filename if present
    filename[strcspn(filename, "\n")] = '\0';

    // Try to open the file in read mode ("r")
    fp = fopen(filename, "r");
    if (fp == NULL) {
        // If the file cannot be opened, print an error message and stop
        printf("Error: Could not open file '%s'\n", filename);
        exit(1);
    }

    // Continue reading until we reach the end of the file
    while (!feof(fp)) {
        count = 0;  // Reset member count for the new family
        sum = 0;    // Reset sum of ages

        // Try to read up to MAX_MEMBERS ages from one line
        while (fscanf(fp, "%d", &age) == 1) {
            family[count++] = age; // Store the age in the array
            sum += age;            // Add age to the total sum

            // Peek ahead to check if we've reached end of the line or file
            int ch = fgetc(fp);
            if (ch == '\n' || ch == EOF) {
                break; // End of the family line reached
            } else {
                ungetc(ch, fp); // Put the character back if it's not newline
            }
        }

        if (count > 0) {
            // Calculate average for the family
            float average = sum / count;

            // Print the average with 2 decimal places
            printf("%5.2f: ", average);

            // Print the original ages from the line
            for (int i = 0; i < count; i++) {
                printf("%d ", family[i]);
            }

            printf("\n"); // Move to the next line after printing a family
        }
    }

    // Close the file after reading all data
    fclose(fp);

    return 0; // End of program
}
