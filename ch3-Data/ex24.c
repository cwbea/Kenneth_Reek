#include <stdio.h>

// File-scope variables
static int w = 5;     // Internal linkage, initialized to 5
extern int x;         // External linkage, defined elsewhere
static int z;         // Internal linkage, initialized to 0

// Function 1: internal linkage
static float func1(int a, int b, int c)
{
    // Local variables
    int d, e = 1;

    {
        int d2, e2, w2;  // New block-scoped locals
        // some logic could go here
    }

    {
        register int b2; // Fast-access local (no address can be taken)
        extern int y;    // Refers to external variable y
        // some logic could go here
    }

    return 0.0f;
}

// Function 2: external linkage
float func2(int a)
{
    extern int y;        // Refers to external variable y

    static int b = 0, c = 0, d = 0;  // Static locals, retain value
    int a2 = 0, d2 = 0, x2 = 0;      // Automatic locals

    y = 2; // Assuming y is defined elsewhere

    return 0.0f;
}

