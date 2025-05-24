/*
** A stack implemented with a dynamically allocated array.
** The array size is specified when create_stack is called.
** This function must be called before using any other stack functions.
*/

#include "stack.h"     // Include the interface for the stack
#include <stdio.h>     // Standard input/output (not directly used here)
#include <stdlib.h>    // For malloc and free
#include <malloc.h>    // Memory allocation (optional, covered by stdlib)
#include <assert.h>    // For runtime checks

// The array that holds stack values, its size, and the index of the top element.
static STACK_TYPE *stack;      // Pointer to the dynamic stack array
static size_t stack_size;      // Number of elements the stack can hold
static int top_element = -1;   // Index of the topmost element (-1 means stack is empty)

/*
** create_stack
** Dynamically allocates memory for the stack.
** Must be called before using the stack.
*/
void create_stack(size_t size)
{
    assert(stack_size == 0);  // Ensure stack is not already created
    stack_size = size;        // Store the size
    stack = malloc(stack_size * sizeof(STACK_TYPE)); // Allocate memory for the stack
    assert(stack != NULL);    // Ensure memory allocation succeeded
}

/*
** destroy_stack
** Frees the memory allocated for the stack and resets it.
*/
void destroy_stack(void)
{
    assert(stack_size > 0);  // Make sure the stack was previously created
    stack_size = 0;          // Reset stack size
    free(stack);             // Free the memory
    stack = NULL;            // Set pointer to NULL to avoid dangling reference
}

/*
** push
** Adds a new value on top of the stack.
*/
void push(STACK_TYPE value)
{
    assert(!is_full());          // Ensure stack is not full
    top_element += 1;            // Move top index up
    stack[top_element] = value;  // Store the new value at the top
}

/*
** pop
** Removes the top value from the stack.
*/
void pop(void)
{
    assert(!is_empty());   // Ensure the stack is not empty
    top_element -= 1;      // Move top index down (effectively discards the top value)
}

/*
** top
** Returns the value at the top of the stack without removing it.
*/
STACK_TYPE top(void)
{
    assert(!is_empty());        // Ensure the stack is not empty
    return stack[top_element]; // Return the top value
}

/*
** is_empty
** Returns 1 (TRUE) if the stack is empty, else 0 (FALSE).
*/
int is_empty(void)
{
    assert(stack_size > 0);         // Ensure stack has been created
    return top_element == -1;       // Empty if top index is -1
}

/*
** is_full
** Returns 1 (TRUE) if the stack is full, else 0 (FALSE).
*/
int is_full(void)
{
    assert(stack_size > 0);               // Ensure stack has been created
    return top_element == stack_size - 1; // Full if top index is last position
}

