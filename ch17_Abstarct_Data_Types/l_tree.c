/*
** A binary search tree implemented by linking dynamically allocated structures.
*/

#include "tree.h"
#include <assert.h>
#include <stdio.h>
#include <malloc.h>  // Optional; stdlib.h is preferred for malloc

/*
** The TreeNode structure holds the value and pointers for one tree node.
*/
typedef struct TREE_NODE {
    TREE_TYPE value;
    struct TREE_NODE *left;
    struct TREE_NODE *right;
} TreeNode;

/*
** Pointer to the root node in the tree.
*/
static TreeNode *tree = NULL;

/*
** insert
**
** Adds a new value to the tree. Does not allow duplicates.
*/
void insert(TREE_TYPE value) {
    TreeNode *current;
    TreeNode **link = &tree;  // Start at the root

    // Traverse to find the correct insertion point
    while ((current = *link) != NULL) {
        if (value < current->value) {
            link = &current->left;
        } else {
            assert(value != current->value); // Duplicate values not allowed
            link = &current->right;
        }
    }

    // Allocate and initialize the new node
    current = (TreeNode *)malloc(sizeof(TreeNode));
    assert(current != NULL);
    current->value = value;
    current->left = NULL;
    current->right = NULL;

    *link = current;  // Link the new node into the tree
}

/*
** find
**
** Searches for a value in the tree.
** Returns a pointer to the value if found, or NULL if not found.
*/
TREE_TYPE *find(TREE_TYPE value) {
    TreeNode *current = tree;

    // Traverse the tree
    while (current != NULL && current->value != value) {
        if (value < current->value) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (current != NULL)
        return &current->value;
    else
        return NULL;
}

/*
** do_pre_order_traverse
**
** Helper function to perform one level of pre-order traversal.
** Calls the callback on each node’s value.
*/
static void do_pre_order_traverse(TreeNode *current, void (*callback)(TREE_TYPE value)) {
    if (current != NULL) {
        callback(current->value);                             // Visit current
        do_pre_order_traverse(current->left, callback);       // Visit left subtree
        do_pre_order_traverse(current->right, callback);      // Visit right subtree
    }
}

/*
** pre_order_traverse
**
** Performs a pre-order traversal of the tree using the client's callback.
*/
void pre_order_traverse(void (*callback)(TREE_TYPE value)) {
    do_pre_order_traverse(tree, callback);
}

