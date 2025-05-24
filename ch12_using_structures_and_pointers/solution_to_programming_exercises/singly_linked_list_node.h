#ifndef SINGLY_LINKED_LIST_NODE_H
#define SINGLY_LINKED_LIST_NODE_H

// Definition of a node in a singly linked list
typedef struct NODE {
    int value;              // Value stored in the node
    struct NODE *link;      // Pointer to the next node in the list
} Node;

#endif

