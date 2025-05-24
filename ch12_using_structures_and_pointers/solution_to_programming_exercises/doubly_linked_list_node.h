#ifndef DOUBLY_LINKED_LIST_NODE_H
#define DOUBLY_LINKED_LIST_NODE_H

// Node definition for a doubly linked list
typedef struct NODE {
    int value;               // Integer value stored in the node
    struct NODE *fwd;        // Pointer to the next node in the list (forward link)
    struct NODE *bwd;        // Pointer to the previous node in the list (backward link)
} Node;

#endif

