/*
** A stack implemented with a static array.
** The array size can be adjusted by changing STACK_SIZE and recompiling.
*/

#include "stack.h"     // Include the stack interface
#include <assert.h>    // Include assert to validate conditions at runtime

// Define the maximum number of values the stack can hold
#define STACK_SIZE 100

/*
** The array that holds the values on the stack,
** and a variable that keeps track of the top element index.
*/
static STACK_TYPE stack[STACK_SIZE];  // The stack itself
static int top_element = -1;          // Index of the top element (-1 means empty)

/*
** push
** Adds a new value to the top of the stack.
*/
void push(STACK_TYPE value)
{
    assert(!is_full());                    // Check: stack should not be full
    top_element += 1;                     // Move the top index up
    stack[top_element] = value;          // Store the value at the new top
}

/*
** pop
** Removes the top value from the stack (discards it).
*/
void pop(void)
{
    assert(!is_empty());                  // Check: stack should not be empty
    top_element -= 1;                    // Move the top index down (removes top element)
}

/*
** top
** Returns the value currently at the top of the stack, without removing it.
*/
STACK_TYPE top(void)
{
    assert(!is_empty());                  // Check: stack should not be empty
    return stack[top_element];          // Return the top value
}

/*
** is_empty
** Returns 1 (TRUE) if the stack is empty, otherwise 0 (FALSE).
*/
int is_empty(void)
{
    return top_element == -1;            // Stack is empty if top is -1
}

/*
** is_full
** Returns 1 (TRUE) if the stack is full, otherwise 0 (FALSE).
*/
int is_full(void)
{
    return top_element == STACK_SIZE - 1; // Stack is full if top index is at last position
}

