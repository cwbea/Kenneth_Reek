#include <stdio.h>
#include <string.h>

// Arrays of number words for 1-19 and tens multiples (20, 30, 40, etc.)
const char *ones[] = {
    "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE",
    "TEN", "ELEVEN", "TWELVE", "THIRTEEN", "FOURTEEN", "FIFTEEN", "SIXTEEN", "SEVENTEEN", 
    "EIGHTEEN", "NINETEEN"
};

const char *tens[] = {
    "", "", "TWENTY", "THIRTY", "FORTY", "FIFTY", "SIXTY", "SEVENTY", "EIGHTY", "NINETY"
};

const char *thousands[] = {
    "", "THOUSAND", "MILLION", "BILLION", "TRILLION"
};

// Helper function to convert numbers from 1-999 to words
void convert_hundreds(unsigned int n, char *buffer) {
    if (n == 0) {
        return; // If n is zero, nothing to convert
    }
    if (n >= 100) {
        strcat(buffer, ones[n / 100]);   // Adds the word for the hundreds place
        strcat(buffer, " HUNDRED ");      // Adds "HUNDRED" after the word
        n = n % 100;                      // Gets the remaining number after removing hundreds
    }
    if (n >= 20) {
        strcat(buffer, tens[n / 10]);     // Adds the word for tens place (20, 30, etc.)
        strcat(buffer, " ");              // Adds space after the tens word
        n = n % 10;                       // Gets the remaining number after removing tens
    }
    if (n > 0) {
        strcat(buffer, ones[n]);          // Adds the word for the ones place (1-9)
        strcat(buffer, " ");              // Adds space after the ones word
    }
}

// Function to convert an amount into words and store it in the buffer
void written_amount(unsigned int amount, char *buffer) {
    if (amount == 0) {
        strcpy(buffer, "ZERO");  // If the amount is zero, directly return "ZERO"
        return;
    }

    char temp[200];  // Temporary buffer to store partial results
    temp[0] = '\0';  // Initialize the temporary buffer to an empty string

    int thousand_index = 0;  // This variable helps in adding place values like "THOUSAND", "MILLION"

    // Process the number in chunks of 1000
    while (amount > 0) {
        unsigned int chunk = amount % 1000;  // Extract the last 3 digits (chunk)
        if (chunk > 0) {
            char chunk_buffer[100];  // Temporary buffer for the chunk
            chunk_buffer[0] = '\0';  // Initialize it to empty string
            convert_hundreds(chunk, chunk_buffer);  // Convert the chunk to words

            if (thousand_index > 0) {
                strcat(chunk_buffer, thousands[thousand_index]);  // Add the place value (THOUSAND, MILLION, etc.)
                strcat(chunk_buffer, " ");  // Add a space after the place value
            }

            // Add the chunk to the temporary result
            if (strlen(temp) > 0) {
                strcat(chunk_buffer, temp);  // Append previous result if any
            }

            strcpy(temp, chunk_buffer);  // Store the updated result in temp
        }

        amount /= 1000;  // Reduce the amount by dividing it by 1000 (move to the next chunk)
        thousand_index++;  // Move to the next place value (thousand, million, etc.)
    }

    // Copy the final result into the buffer
    strcpy(buffer, temp);
}

int main() {
    unsigned int value = 16312;  // This is the amount we want to convert
    char buffer[500];  // Buffer to hold the final result (make sure it's large enough)

    written_amount(value, buffer);  // Call the function to convert the amount

    printf("Amount in words: %s\n", buffer);  // Print the final result

    return 0;
}

