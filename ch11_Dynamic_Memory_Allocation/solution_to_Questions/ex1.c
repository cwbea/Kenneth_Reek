#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

#define MAX_MB 2048  // Max test limit: 2GB                  //ulimit-s 8192kb 
#define MB (1024 * 1024)

jmp_buf env;

// Try static allocation (on stack)
void test_stack_allocation(size_t size_mb) {
    volatile char buffer[size_mb * MB]; // Try to allocate on stack
    buffer[0] = 0; // Access to ensure allocation
    buffer[size_mb * MB - 1] = 1;
    printf("Stack allocation succeeded: %zu MB\n", size_mb);
}

// Try dynamic allocation (on heap)
void test_heap_allocation() {
    size_t size_mb = 1;
    while (size_mb <= MAX_MB) {
        char *buffer = malloc(size_mb * MB);
        if (buffer == NULL) {
            printf("Heap allocation failed at %zu MB\n", size_mb);
            break;
        }
        buffer[0] = 0;
        buffer[size_mb * MB - 1] = 1;
        free(buffer);
        printf("Heap allocation succeeded: %zu MB\n", size_mb);
        size_mb *= 2;
    }
}

int main() {
    printf("=== Dynamic (Heap) Allocation Test ===\n");
    test_heap_allocation();

    printf("\n=== Static (Stack) Allocation Test ===\n");
    size_t stack_sizes[] = {1, 2, 4, 8, 16, 32, 64}; // MB
    for (int i = 0; i < sizeof(stack_sizes)/sizeof(stack_sizes[0]); i++) {
        size_t size_mb = stack_sizes[i];
        if (!setjmp(env)) {
            test_stack_allocation(size_mb);
        } else {
            printf("Stack allocation failed at %zu MB\n", size_mb);
            break;
        }
    }

    return 0;
}


