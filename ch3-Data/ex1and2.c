#include <stdio.h>    // For input and output functions like printf
#include <limits.h>   // For integer type limits (e.g., INT_MAX)
#include <float.h>    // For floating-point type limits (e.g., FLT_MAX)

int main(void) {
    // Print the sizes (in bytes) of various data types
    printf("===== SIZE OF TYPES (bytes) =====\n");
    printf("char       : %zu\n", sizeof(char));          // Size of char
    printf("short      : %zu\n", sizeof(short));         // Size of short int
    printf("int        : %zu\n", sizeof(int));           // Size of int
    printf("long       : %zu\n", sizeof(long));          // Size of long int
    printf("long long  : %zu\n", sizeof(long long));     // Size of long long int
    printf("float      : %zu\n", sizeof(float));         // Size of float
    printf("double     : %zu\n", sizeof(double));        // Size of double
    printf("long double: %zu\n\n", sizeof(long double)); // Size of long double

    // Print the limits (minimum/maximum values) of character types
    printf("===== CHAR LIMITS =====\n");
    printf("CHAR_BIT   : %d\n", CHAR_BIT);      // Number of bits in a byte (usually 8)
    printf("CHAR_MIN   : %d\n", CHAR_MIN);      // Minimum value of a char
    printf("CHAR_MAX   : %d\n", CHAR_MAX);      // Maximum value of a char
    printf("SCHAR_MIN  : %d\n", SCHAR_MIN);     // Minimum value of a signed char
    printf("SCHAR_MAX  : %d\n", SCHAR_MAX);     // Maximum value of a signed char
    printf("UCHAR_MAX  : %u\n\n", UCHAR_MAX);   // Maximum value of an unsigned char

    // Print the limits for integer types (int, short, long)
    printf("===== INTEGER LIMITS =====\n");
    printf("INT_MIN    : %d\n", INT_MIN);       // Minimum value of an int
    printf("INT_MAX    : %d\n", INT_MAX);       // Maximum value of an int
    printf("UINT_MAX   : %u\n\n", UINT_MAX);    // Maximum value of an unsigned int

    printf("SHORT_MIN  : %d\n", SHRT_MIN);      // Minimum value of a short int
    printf("SHORT_MAX  : %d\n", SHRT_MAX);      // Maximum value of a short int
    printf("USHRT_MAX  : %u\n\n", USHRT_MAX);   // Maximum value of an unsigned short int

    printf("LONG_MIN   : %ld\n", LONG_MIN);     // Minimum value of a long int
    printf("LONG_MAX   : %ld\n", LONG_MAX);     // Maximum value of a long int
    printf("ULONG_MAX  : %lu\n\n", ULONG_MAX);  // Maximum value of an unsigned long int

    printf("LLONG_MIN  : %lld\n", LLONG_MIN);   // Minimum value of a long long int
    printf("LLONG_MAX  : %lld\n", LLONG_MAX);   // Maximum value of a long long int

