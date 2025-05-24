#include <stdio.h>

unsigned int reverse_bits(unsigned int value) {
    unsigned int result = 0;          // This will store the reversed bit result
    int i;

    // Loop exactly 32 times, since we're working with 32-bit integers
    for (i = 0; i < 32; i++) {
        // Shift result to the left by 1 to make space for the next bit
        result <<= 1;

        // Take the least significant bit (rightmost bit) from value
        // and add it to result using bitwise OR
        result |= (value & 1);

        // Shift value to the right by 1 to process the next bit
        value >>= 1;
    }

    // After the loop, result contains the reversed bits
    return result;
}

int main() {
    unsigned int original = 25;
    unsigned int reversed = reverse_bits(original);

    // Print the result
    printf("Original: %u\n", original);
    printf("Reversed: %u\n", reversed);

    return 0;
}

