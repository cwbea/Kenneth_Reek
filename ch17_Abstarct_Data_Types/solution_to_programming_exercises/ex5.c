#include <stdio.h>   // For input/output functions like printf
#include <stdlib.h>  // For memory allocation (malloc) and deallocation (free)

// Define a structure for a node in the binary search tree
typedef struct TreeNode {
    int value;                  // The integer value stored in the node
    struct TreeNode* left;     // Pointer to the left child (NULL if no child)
    struct TreeNode* right;    // Pointer to the right child (NULL if no child)
} TreeNode;

// Function: create_node
// Purpose: Creates and initializes a new tree node with the given value
// Parameters: int value - the value to be stored in the node
// Returns: pointer to the new TreeNode
TreeNode* create_node(int value) {
    // Allocate memory for a new TreeNode
    TreeNode* new_node = (TreeNode*)malloc(sizeof(TreeNode));

    // Assign the given value to the node
    new_node->value = value;

    // Initially, the new node has no children
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;  // Return the pointer to the newly created node
}

// Function: insert
// Purpose: Inserts a new value into the binary search tree (BST)
// Parameters:
//    TreeNode* root - pointer to the current root of the tree (or subtree)
//    int value      - the value to insert
// Returns: Updated root pointer (in case the root is NULL)
TreeNode* insert(TreeNode* root, int value) {
    // If the tree/subtree is empty, create and return a new node
    if (root == NULL) {
        return create_node(value);
    }

    // If the value is less than the current node's value,
    // insert it into the left subtree
    if (value < root->value) {
        root->left = insert(root->left, value);
    }
    // If the value is greater than or equal to the current node's value,
    // insert it into the right subtree
    else {
        root->right = insert(root->right, value);
    }

    return root;  // Return the unchanged root pointer
}

// Function: count_nodes
// Purpose: Counts the total number of nodes in the BST
// Parameters: TreeNode* root - pointer to the root of the tree
// Returns: The total number of nodes in the tree (int)
int count_nodes(TreeNode* root) {
    // Base case: if root is NULL, return 0 (no node to count)
    if (root == NULL) {
        return 0;
    }

    // Recursive case:
    // 1 (this node) + number of nodes in left subtree + number in right subtree
    return 1 + count_nodes(root->left) + count_nodes(root->right);
}

// Function: destroy_tree
// Purpose: Frees all memory allocated for the tree nodes
// Parameters: TreeNode* root - pointer to the root of the tree
// Returns: void
void destroy_tree(TreeNode* root) {
    // If the current node is NULL, nothing to free
    if (root == NULL) return;

    // Recursively free the left subtree
    destroy_tree(root->left);

    // Recursively free the right subtree
    destroy_tree(root->right);

    // Free the current node
    free(root);
}

// Function: main
// Purpose: Entry point of the program; demonstrates the BST and node count
int main() {
    TreeNode* root = NULL;  // Start with an empty binary search tree

    // Insert values into the tree (in this order)
    root = insert(root, 20);  // Root node
    root = insert(root, 10);  // Left of 20
    root = insert(root, 30);  // Right of 20
    root = insert(root, 5);   // Left of 10
    root = insert(root, 15);  // Right of 10
    root = insert(root, 25);  // Left of 30
    root = insert(root, 35);  // Right of 30

    // Count and display the number of nodes in the tree
    int total_nodes = count_nodes(root);
    printf("Total number of nodes in the tree: %d\n", total_nodes);

    // Free all memory used by the tree before exiting
    destroy_tree(root);

    return 0;  // Exit the program successfully
}

