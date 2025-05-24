/*  What is wrong and what happens:
1. setjmp return value is ignored

    setjmp returns an int that indicates how the control reached the setjmp call:

        Returns 0 if called directly.

        Returns non-zero (the value passed in longjmp) if returning after a longjmp.

    Problem: The program ignores this value, so it does not distinguish between the first call and the jump-back.

2. Infinite loop behavior because of longjmp

    setjmp(jbuf) saves the context inside set_buffer().

    The first time, setjmp returns 0; then the program prints a + b.

    Then longjmp(jbuf, 1) jumps back to the saved context inside set_buffer().

    This causes setjmp to return 1 now.

    But since the program does not check the return value of setjmp, it continues as if it was called the first time
    — so it again prints the sum and calls longjmp again.

    Result: The program keeps jumping back and printing endlessly — an infinite loop.

3. printf("After longjmp\n"); will never run

    After longjmp, execution resumes inside setjmp, so the code after longjmp is skipped.

4. Missing #include <stdio.h>

    For printf to work, you need to include <stdio.h>.

How to fix this:

Check the return value of setjmp to differentiate the first call from the longjmp return:
*/


#include <stdlib.h>
#include <stdio.h>
#include <setjmp.h>

jmp_buf jbuf;

void set_buffer()
{
    // This function should not call setjmp alone if you want to handle return values
    // Best to call setjmp in main or capture return value here
}

int main(int ac, char **av)
{
    if (ac < 3) {
        fprintf(stderr, "Usage: %s num1 num2\n", av[0]);
        return EXIT_FAILURE;
    }

    int a = atoi(av[1]);
    int b = atoi(av[2]);

    int val = setjmp(jbuf);  // Save context, val indicates return reason

    if (val == 0) {
        // First time here, just proceed and then jump back
        printf("%d plus %d equals %d\n", a, b, a + b);
        longjmp(jbuf, 1);  // Jump back to setjmp, with return value 1
    } else {
        // Returned here from longjmp
        printf("Returned via longjmp with value %d\n", val);
    }

    printf("Program continues here...\n");

    return EXIT_SUCCESS;
}




/*Summary:

    Your original program ignores the return value of setjmp, so when longjmp jumps back, it repeats forever.

    longjmp causes execution to resume at the point of the last setjmp call with a nonzero return.

    The code after longjmp is not executed.

    Always check the return value of setjmp to distinguish between the initial call and a jump-back. */

