#include <stdio.h>

typedef enum { NEW, DELETE, FORWARD, BACKWARD, SEARCH, EDIT, NUM_TYPES } Trans_type;

typedef struct Node {
    struct Node *next;
    struct Node *prev;
    // other members...
} Node;

typedef struct {
    // transaction fields...
} Transaction;

// Forward declarations of functions used
void add_new_trans(Node *list, Transaction *transaction);
Node *delete_trans(Node *list, Node *current);
Node *search(Node *list, Transaction *transaction);
void edit(Node *current, Transaction *transaction);

// Wrapper function typedef for all handlers
typedef Node *(*TransHandler)(Node *list, Node *current, Transaction *transaction);

// Handler functions for each type
Node *handle_new(Node *list, Node *current, Transaction *transaction) {
    add_new_trans(list, transaction);
    return current;
}

Node *handle_delete(Node *list, Node *current, Transaction *transaction) {
    return delete_trans(list, current);
}

Node *handle_forward(Node *list, Node *current, Transaction *transaction) {
    return current ? current->next : NULL;
}

Node *handle_backward(Node *list, Node *current, Transaction *transaction) {
    return current ? current->prev : NULL;
}

Node *handle_search(Node *list, Node *current, Transaction *transaction) {
    return search(list, transaction);
}

Node *handle_edit(Node *list, Node *current, Transaction *transaction) {
    edit(current, transaction);
    return current;
}

// Jump table array of function pointers
TransHandler jump_table[NUM_TYPES] = {
    handle_new,
    handle_delete,
    handle_forward,
    handle_backward,
    handle_search,
    handle_edit
};

// Usage:
void process_transaction(Trans_type type, Node *list, Node **current, Transaction *transaction) {
    if (type >= 0 && type < NUM_TYPES) {
        *current = jump_table[type](list, *current, transaction);
    } else {
        printf("Illegal transaction type!\n");
    }
}

