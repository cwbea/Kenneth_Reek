/*
** Interface for a stack module
*/

#ifndef STACK_H
#define STACK_H

// Define the type of value that will be stored in the stack
#define STACK_TYPE int

/*
** push
** Pushes a new value on the stack.
** Argument: value - the value to be pushed.
*/
void push(STACK_TYPE value);

/*
** pop
** Pops a value off of the stack, discarding it.
*/
void pop(void);

/*
** top
** Returns the topmost value on the stack without changing the stack.
*/
STACK_TYPE top(void);

/*
** is_empty
** Returns 1 (TRUE) if the stack is empty, else 0 (FALSE).
*/
int is_empty(void);

/*
** is_full
** Returns 1 (TRUE) if the stack is full, else 0 (FALSE).
*/
int is_full(void);

#endif // STACK_H

