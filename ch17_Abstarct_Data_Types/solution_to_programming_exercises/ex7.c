#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // For INT_MIN and INT_MAX

// ------------------------------------
// Binary tree node structure
// ------------------------------------
typedef struct Node {
    int data;              // Value stored in the node
    struct Node *left;     // Pointer to the left child
    struct Node *right;    // Pointer to the right child
} Node;

// ------------------------------------
// Create a new node with given value
// ------------------------------------
// Parameters:
//   value - integer data for the new node
// Returns:
//   Pointer to the newly created node
Node* create_node(int value) {
    Node* new_node = (Node*)malloc(sizeof(Node)); // Allocate memory for the new node
    new_node->data = value;    // Assign value
    new_node->left = NULL;     // Set left child to NULL
    new_node->right = NULL;    // Set right child to NULL
    return new_node;           // Return the pointer to new node
}

// --------------------------------------------
// Recursive function to check if a binary tree
// is a binary search tree (BST)
// --------------------------------------------
// A BST has the property:
//   Left subtree < current node < Right subtree
//
// Parameters:
//   root  - current node in the tree
//   min   - minimum allowed value for current node (all left children must be less)
//   max   - maximum allowed value for current node (all right children must be greater)
//
// Returns:
//   1 if subtree rooted at root is a BST, otherwise 0
int is_bst(Node* root, int min, int max) {
    if (root == NULL) {
        return 1; // An empty tree is a valid BST
    }

    // Check current node: must lie between min and max (exclusive)
    if (root->data <= min || root->data >= max) {
        return 0; // Violation of BST property
    }

    // Recursively check left and right subtrees:
    // - left subtree must have values < root->data
    // - right subtree must have values > root->data
    return is_bst(root->left, min, root->data) &&
           is_bst(root->right, root->data, max);
}

// ------------------------------------
// Wrapper function to simplify the call
// ------------------------------------
// This starts the BST check with full range of valid int values
// Parameter:
//   root - root node of the binary tree
// Returns:
//   1 if it's a BST, 0 otherwise
int is_binary_search_tree(Node* root) {
    return is_bst(root, INT_MIN, INT_MAX);
}

// ------------------------------------
// Main function
// ------------------------------------
int main() {
    // Construct the binary tree manually
    //
    //         20
    //        /  \
    //      10    30
    //     /  \     \
    //    5   15     40
    //
    // This is a valid BST

    Node* root = create_node(20);
    root->left = create_node(10);
    root->right = create_node(30);
    root->left->left = create_node(5);
    root->left->right = create_node(15);
    root->right->right = create_node(40);

    // Call the function to check if this is a BST
    if (is_binary_search_tree(root)) {
        printf("This is a binary search tree.\n");
    } else {
        printf("This is NOT a binary search tree.\n");
    }

    // Modify the tree to break the BST property
    root->right->left = create_node(8); // Invalid node: 8 < 20 but is in the right subtree

    // Check again
    if (is_binary_search_tree(root)) {
        printf("This is a binary search tree.\n");
    } else {
        printf("This is NOT a binary search tree.\n");
    }

    return 0; // Exit the program
}

