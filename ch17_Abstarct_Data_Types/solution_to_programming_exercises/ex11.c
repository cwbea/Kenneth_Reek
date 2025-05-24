#include <stdio.h>
#include <assert.h>

// Macro to declare a stack structure and its interface functions
#define DECLARE_STACK_INTERFACE(TYPE, SUFFIX) \
typedef struct { \
    TYPE *data;            /* Pointer to the array holding the stack elements */ \
    int top;               /* Index of the top element in the stack */ \
    int size;              /* Maximum number of elements the stack can hold */ \
} Stack##SUFFIX; \
\
int is_empty##SUFFIX(Stack##SUFFIX *s); \
int is_full##SUFFIX(Stack##SUFFIX *s); \
void push##SUFFIX(Stack##SUFFIX *s, TYPE value); \
void pop##SUFFIX(Stack##SUFFIX *s); \
TYPE top##SUFFIX(Stack##SUFFIX *s);

// Macro to define the implementation of the stack functions
#define DEFINE_STACK_IMPLEMENTATION(TYPE, SUFFIX) \
int is_empty##SUFFIX(Stack##SUFFIX *s) { \
    return s->top == -1; \
} \
\
int is_full##SUFFIX(Stack##SUFFIX *s) { \
    return s->top == s->size - 1; \
} \
\
void push##SUFFIX(Stack##SUFFIX *s, TYPE value) { \
    assert(!is_full##SUFFIX(s));  /* Ensure the stack is not full before pushing */ \
    s->top += 1; \
    s->data[s->top] = value; \
} \
\
void pop##SUFFIX(Stack##SUFFIX *s) { \
    assert(!is_empty##SUFFIX(s)); /* Ensure the stack is not empty before popping */ \
    s->top -= 1; \
} \
\
TYPE top##SUFFIX(Stack##SUFFIX *s) { \
    assert(!is_empty##SUFFIX(s)); /* Ensure the stack is not empty before accessing top */ \
    return s->data[s->top]; \
}

// Macro to create and initialize the stack data
#define CREATE_STACK(TYPE, SUFFIX, STACK_VAR, STACK_SIZE) \
TYPE STACK_VAR##_data[STACK_SIZE]; \
Stack##SUFFIX STACK_VAR = { STACK_VAR##_data, -1, STACK_SIZE };

// Use the macros to create a stack for integers with suffix Int and size 10
DECLARE_STACK_INTERFACE(int, Int)
DEFINE_STACK_IMPLEMENTATION(int, Int)

int main() {
    // Create a stack of integers named myStack that can hold 10 elements
    CREATE_STACK(int, Int, myStack, 10)

    // Push values onto the stack
    pushInt(&myStack, 5);
    pushInt(&myStack, 10);
    pushInt(&myStack, 15);

    // Print the top value on the stack
    printf("Top of stack: %d\n", topInt(&myStack));

    // Pop a value and print the new top
    popInt(&myStack);
    printf("Top after pop: %d\n", topInt(&myStack));

    return 0;
}

