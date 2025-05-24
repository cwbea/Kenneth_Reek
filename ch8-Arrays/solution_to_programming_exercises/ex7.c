#include <stdio.h>
#include <stdarg.h>

// Computes offset into a column-major order pseudo-array
int array_offset2(int arrayinfo[], ...) {
    int i;
    int dimensions = arrayinfo[0];  // Number of dimensions

    // Guard against invalid number of dimensions
    if (dimensions < 1 || dimensions > 10) {
        return -1;
    }

    // Arrays for bounds and sizes
    int low[10], high[10];
    int sizes[10]; // holds the size of each dimension

    // Extract bounds and compute sizes of each dimension
    for (i = 0; i < dimensions; ++i) {
        low[i] = arrayinfo[1 + i * 2];
        high[i] = arrayinfo[2 + i * 2];
        if (low[i] > high[i]) {
            return -1;
        }
        sizes[i] = high[i] - low[i] + 1;
    }

    // Start reading variable arguments (subscripts)
    va_list ap;
    va_start(ap, arrayinfo);

    int subscripts[10];
    for (i = 0; i < dimensions; ++i) {
        subscripts[i] = va_arg(ap, int);
        if (subscripts[i] < low[i] || subscripts[i] > high[i]) {
            va_end(ap);
            return -1;
        }
    }

    va_end(ap);

    // Calculate the offset in column-major order
    int offset = 0;
    int stride = 1;

    for (i = 0; i < dimensions; ++i) {
        offset += (subscripts[i] - low[i]) * stride;
        stride *= sizes[i]; // accumulate size from left to right
    }

    return offset;
}

