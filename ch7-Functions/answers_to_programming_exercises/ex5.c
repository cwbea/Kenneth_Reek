#include <stdio.h>
#include <stdarg.h>  // For va_list and va_start
#include <stdlib.h>  // For itoa (integer to ASCII conversion)

void print_integer(int value) {
    // Prints the integer by converting it to a string and outputting each digit
    printf("%d", value);  // Here we use the built-in printf for simplicity
}

void print_float(float value) {
    // Prints the float using the standard %f format
    printf("%f", value);  // Again, using printf to simplify the task
}

void my_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);  // Initialize args to point to the first variable argument

    while (*format != '\0') {
        if (*format == '%') {  // Check if we have a format specifier
            format++;  // Move past the '%' character
            switch (*format) {
                case 'd': {  // Handle integer format
                    int value = va_arg(args, int);  // Get the next integer argument
                    print_integer(value);  // Call print_integer to print the value
                    break;
                }
                case 'f': {  // Handle float format
                    double value = va_arg(args, double);  // Get the next double argument (float is promoted to double)
                    print_float((float)value);  // Call print_float to print the value
                    break;
                }
                case 's': {  // Handle string format
                    char *str = va_arg(args, char*);  // Get the next string argument
                    for (int i = 0; str[i] != '\0'; i++) {
                        putchar(str[i]);  // Print each character of the string using putchar
                    }
                    break;
                }
                case 'c': {  // Handle char format
                    char c = (char) va_arg(args, int);  // Get the next character argument (promoted to int)
                    putchar(c);  // Print the character using putchar
                    break;
                }
                default:
                    putchar('%');  // If an unrecognized format specifier is found, just print '%'
                    putchar(*format);  // Print the character after '%'
                    break;
            }
        } else {
            putchar(*format);  // Print the current character if no format specifier
        }
        format++;  // Move to the next character
    }

    va_end(args);  // Clean up the va_list
}

int main() {
    // Test the custom printf function
    int age = 25;
    float height = 5.9;
    char initial = 'J';
    char name[] = "John";

    my_printf("Name: %s, Age: %d, Height: %f, Initial: %c\n", name, age, height, initial);

    return 0;
}

