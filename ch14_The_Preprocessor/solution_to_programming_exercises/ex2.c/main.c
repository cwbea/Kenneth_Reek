#include <stdio.h>
#include "cpu_types.h"

int cpu_type(void);  // Declare function

int main(void) {
    int cpu = cpu_type();
    printf("Detected CPU type: %d\n", cpu);
    return 0;
}


/* To Compile with a Specific CPU

You must pass the corresponding CPU symbol using -D:

gcc -DVAX cpu_detect.c main.c -o detect

Or for 80386:

gcc -DI80386 cpu_detect.c main.c -o detect

🔍 Summary

    The function uses #ifdef, #elif, and #else to check which CPU symbol is defined.

    Only one CPU type should be defined at compile time — multiple definitions yield undefined behavior.

    If none are defined, it returns CPU_UNKNOWN. */
