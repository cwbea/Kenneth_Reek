/*
** A binary search tree implemented with a static array.
** The array size can be adjusted only by changing the #define
** and recompiling the module.
*/

#include "tree.h"
#include <assert.h>
#include <stdio.h>

// Max number of values in the tree
#define TREE_SIZE 100

// Actual array size = TREE_SIZE + 1 (because we don't use index 0)
#define ARRAY_SIZE (TREE_SIZE + 1)

// Array to hold the tree values
static TREE_TYPE tree[ARRAY_SIZE];

/*
** left_child
**
** Computes the index of the left child in the array.
** For a node at index `current`, the left child is at index `current * 2`.
*/
static int left_child(int current) {
    return current * 2;
}

/*
** right_child
**
** Computes the index of the right child in the array.
** For a node at index `current`, the right child is at index `current * 2 + 1`.
*/
static int right_child(int current) {
    return current * 2 + 1;
}

/*
** insert
**
** Adds a new value to the tree. Ensures value is not zero (0 means unused node).
*/
void insert(TREE_TYPE value) {
    int current;

    assert(value != 0); // 0 is used to indicate an empty node

    current = 1; // Start at the root node

    // Traverse the tree to find the correct position
    while (tree[current] != 0) {
        if (value < tree[current]) {
            current = left_child(current);
        } else {
            assert(value != tree[current]); // Do not insert duplicate values
            current = right_child(current);
        }

        // Make sure we don’t go beyond the array size
        assert(current < ARRAY_SIZE);
    }

    // Place the value in the found empty spot
    tree[current] = value;
}

/*
** find
**
** Searches for a value in the tree.
** Returns a pointer to the value if found, or NULL if not found.
*/
TREE_TYPE *find(TREE_TYPE value) {
    int current = 1; // Start at root

    while (current < ARRAY_SIZE && tree[current] != value) {
        if (value < tree[current]) {
            current = left_child(current);
        } else {
            current = right_child(current);
        }
    }

    if (current < ARRAY_SIZE && tree[current] != 0) {
        return &tree[current];
    } else {
        return NULL;
    }
}

/*
** do_pre_order_traverse
**
** Helper function for pre-order traversal.
** Calls the callback function on each node in pre-order.
*/
static void do_pre_order_traverse(int current, void (*callback)(TREE_TYPE value)) {
    if (current < ARRAY_SIZE && tree[current] != 0) {
        callback(tree[current]); // Visit current node
        do_pre_order_traverse(left_child(current), callback); // Visit left subtree
        do_pre_order_traverse(right_child(current), callback); // Visit right subtree
    }
}

/*
** pre_order_traverse
**
** Starts the pre-order traversal from the root of the tree.
** Calls the user's callback function on each value.
*/
void pre_order_traverse(void (*callback)(TREE_TYPE value)) {
    do_pre_order_traverse(1, callback); // Begin at root (index 1)
}

