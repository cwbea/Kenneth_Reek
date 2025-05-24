#include <stdio.h>
#include <stdint.h>  // For portable, fixed-width types

int main(void) {
    int16_t small_value = 12345;      // Always 16-bit, even on 32-bit machine
    int32_t large_value = 123456789;  // Always 32-bit

    printf("Small value: %d\n", small_value);
    printf("Large value: %d\n", large_value);

    return 0;
}

