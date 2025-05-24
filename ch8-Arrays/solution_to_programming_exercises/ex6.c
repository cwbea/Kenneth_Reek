#include <stdio.h>
#include <stdarg.h>

// This function computes the offset into a 1D vector that represents a multi-dimensional pseudo-array
int array_offset(int arrayinfo[], ...) {
    int i;
    int dimensions = arrayinfo[0];  // arrayinfo[0] holds the number of dimensions

    // Check for invalid number of dimensions
    if (dimensions < 1 || dimensions > 10) {
        return -1;
    }

    // Arrays to store low and high bounds for each dimension
    int low[10], high[10];

    // Extract the low and high bounds for each dimension
    for (i = 0; i < dimensions; ++i) {
        low[i] = arrayinfo[1 + i * 2];      // Low bound for dimension i
        high[i] = arrayinfo[2 + i * 2];     // High bound for dimension i

        // Check if the bounds are valid
        if (low[i] > high[i]) {
            return -1;
        }
    }

    va_list ap;
    va_start(ap, arrayinfo);

    int subscripts[10];  // Store actual subscript values passed by the user

    for (i = 0; i < dimensions; ++i) {
        subscripts[i] = va_arg(ap, int);  // Get each subscript

        // Check if subscript is within its valid range
        if (subscripts[i] < low[i] || subscripts[i] > high[i]) {
            va_end(ap);
            return -1;
        }
    }

    va_end(ap);

    // Compute offset
    int offset = 0;
    int size = 1;

    // Work from the last dimension to the first for proper offset calculation
    for (i = dimensions - 1; i >= 0; --i) {
        offset += (subscripts[i] - low[i]) * size;
        size *= (high[i] - low[i] + 1);  // Update size for next outer dimension
    }

    return offset;
}

