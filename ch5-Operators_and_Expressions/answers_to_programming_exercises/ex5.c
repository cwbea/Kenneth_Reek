#include <stdio.h>

int store_bit_field(int original_value, int value_to_store,
                    unsigned starting_bit, unsigned ending_bit) {
    // Step 1: Calculate how many bits are in the field
    int num_bits = starting_bit - ending_bit + 1;

    // Step 2: Create a mask with num_bits 1s
    int mask = (1 << num_bits) - 1;

    // Step 3: Align the mask to the correct bit positions
    int shifted_mask = mask << ending_bit;

    // Step 4: Clear the target bits in original_value
    original_value &= ~shifted_mask;

    // Step 5: Mask and align value_to_store
    int bits_to_store = (value_to_store & mask) << ending_bit;

    // Step 6: OR the bits into the cleared original_value
    original_value |= bits_to_store;

    return original_value;
}

