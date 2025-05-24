#include <stdio.h>
#include <stdlib.h>

#define CHUNK_SIZE 500     // or try 5000
#define MAX_BLOCKS 1000000

int main() {
    void *ptrs[MAX_BLOCKS];
    size_t count = 0;

    while (count < MAX_BLOCKS) {
        ptrs[count] = malloc(CHUNK_SIZE);
        if (ptrs[count] == NULL) break;
        count++;
    }

    printf("Allocated %zu blocks of %d bytes = %.2f MB\n",
           count, CHUNK_SIZE, (count * CHUNK_SIZE) / (1024.0 * 1024.0));

    // Clean up
    for (size_t i = 0; i < count; i++)
        free(ptrs[i]);

    return 0;
}

