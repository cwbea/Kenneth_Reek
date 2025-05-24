#include <stdio.h>      // For input/output functions like printf
#include <signal.h>     // For handling signals like SIGFPE (arithmetic exceptions)
#include <stdlib.h>     // For general utilities (like exit)
#include <setjmp.h>     // For non-local jumps with setjmp and longjmp

static jmp_buf jump_buffer; // Buffer to store the program state for longjmp to return to

// Signal handler function to catch SIGFPE signals (like division by zero)
void sigfpe_handler(int sig) {
    // sig: the signal number received, here it will be SIGFPE
    printf("Caught SIGFPE: Arithmetic exception (signal %d)\n", sig);
    // Jump back to the saved state in jump_buffer, passing value 1
    longjmp(jump_buffer, 1);
}

int main() {
    // Install the sigfpe_handler as the handler for SIGFPE signals
    signal(SIGFPE, sigfpe_handler);

    // Test integer division by zero
    // setjmp returns 0 the first time, and non-zero when returning from longjmp
    if (setjmp(jump_buffer) == 0) {
        int a = 10;       // Integer numerator for division
        int b = 0;        // Integer denominator (zero, causes division by zero)
        printf("Testing integer division by zero...\n");
        int c = a / b;    // This causes a SIGFPE on most systems (division by zero error)
        printf("Result (int division): %d\n", c); // This line normally won't run due to error above
    } else {
        // This block runs if longjmp is called after catching SIGFPE from integer division
        printf("Handled SIGFPE from integer division.\n");
    }

    // Test floating-point division by zero
    // Again, setjmp returns 0 first, non-zero when returning from longjmp
    if (setjmp(jump_buffer) == 0) {
        double x = 10.0;  // Floating-point numerator
        double y = 0.0;   // Floating-point denominator zero
        printf("Testing floating-point division by zero...\n");
        double z = x / y; // Floating-point division by zero; usually returns +inf or -inf, might not cause SIGFPE
        printf("Result (float division): %f\n", z); // Print result of floating division
    } else {
        // Runs if floating-point division triggered SIGFPE and longjmp was called
        printf("Handled SIGFPE from floating-point division.\n");
    }

    printf("Program completed.\n"); // Inform user that program finished normally
    return 0;  // Return success exit code to operating system
}





/*Explanation of results you might see:

    Integer division by zero usually causes SIGFPE because CPUs trap this as an illegal operation.

    Floating-point division by zero often does not cause a signal. Instead, it returns:

        +inf or -inf (infinity),

        or NaN (Not a Number),

    according to IEEE 754 floating-point standard, which most systems follow.

    However, on some systems with special floating-point environment settings, floating-point division by zero may raise SIGFPE.  */
