/*
** Interface for a binary search tree (BST) module
** This defines the basic operations supported by a BST.
*/

#ifndef TREE_H
#define TREE_H

// Define the type of value stored in the tree
#define TREE_TYPE int

/*
** insert
**
** Adds a new value to the tree.
** The argument is the value to be added.
** Assumes the value does not already exist in the tree.
*/
void insert(TREE_TYPE value);

/*
** find
**
** Searches for a specific value in the tree.
** The argument is the value to find.
** Returns a pointer to the value if found, or NULL if not.
*/
TREE_TYPE *find(TREE_TYPE value);

/*
** pre_order_traverse
**
** Performs a pre-order traversal of the tree.
** The function takes a pointer to a callback function.
** This callback will be called once for each value in the tree.
** The value is passed to the callback function.
*/
void pre_order_traverse(void (*callback)(TREE_TYPE value));

#endif // TREE_H

