#include <stdio.h>

// Set the specified bit to 1
void set_bit(char bit_array[], unsigned bit_number) {
    unsigned byte_index = bit_number / 8;         // Which byte holds this bit
    unsigned bit_position = bit_number % 8;       // Position in that byte (0–7)

    bit_array[byte_index] |= (1 << bit_position); // Use OR to set the bit
}

// Clear the specified bit (set to 0)
void clear_bit(char bit_array[], unsigned bit_number) {
    unsigned byte_index = bit_number / 8;
    unsigned bit_position = bit_number % 8;

    bit_array[byte_index] &= ~(1 << bit_position); // Use AND with inverted mask to clear
}

// Assign the bit to 0 or 1 based on the value
void assign_bit(char bit_array[], unsigned bit_number, int value) {
    if (value)
        set_bit(bit_array, bit_number);   // Set if value is non-zero
    else
        clear_bit(bit_array, bit_number); // Clear if value is zero
}

// Test the value of the bit (returns 1 if set, 0 if clear)
int test_bit(char bit_array[], unsigned bit_number) {
    unsigned byte_index = bit_number / 8;
    unsigned bit_position = bit_number % 8;

    return (bit_array[byte_index] >> bit_position) & 1;
}

