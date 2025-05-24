#include <stdio.h>
#include <time.h>
#include <unistd.h>  // For sleep()

int main() {
    clock_t start, end;
    double cpu_time_used;

    // Measure time for a CPU-intensive loop
    start = clock();  // Start timing
    for (volatile long i = 0; i < 100000000; i++);  // Burn CPU cycles
    end = clock();    // End timing
    cpu_time_used = (double)(end - start) / CLOCKS_PER_SEC;
    printf("CPU-intensive time: %f seconds\n", cpu_time_used);

    // Measure time for a sleep (which uses no CPU)
    start = clock();  // Start timing
    sleep(2);         // Sleep for 2 seconds (no CPU usage)
    end = clock();    // End timing
    cpu_time_used = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Sleep time: %f seconds\n", cpu_time_used);

    return 0;
}


/* Your system's clock() function measures CPU time, not elapsed (wall-clock) time.

   That means clock() only increases when your program is actually using the CPU.

This behavior is consistent with the C standard library on Unix-like systems 
(e.g., Linux and macOS), where clock() is designed to return CPU time used by the process,
not wall time */
