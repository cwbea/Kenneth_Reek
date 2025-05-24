#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the binary search tree
typedef struct Node {
    int data;               // The value stored in the node
    struct Node* left;      // Pointer to the left child
    struct Node* right;     // Pointer to the right child
} Node;

// Function to create a new node with the given value
Node* create_node(int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));  // Allocate memory for a new node
    new_node->data = value;     // Set the value
    new_node->left = NULL;      // Initially no left child
    new_node->right = NULL;     // Initially no right child
    return new_node;
}

// Function to insert a value into the binary search tree
Node* insert(Node* root, int value) {
    if (root == NULL) {
        // If tree is empty, create a new node and return it as the root
        return create_node(value);
    }

    if (value < root->data) {
        // If value is smaller, insert it in the left subtree
        root->left = insert(root->left, value);
    } else {
        // If value is greater or equal, insert it in the right subtree
        root->right = insert(root->right, value);
    }

    return root;  // Return the root (unchanged)
}

// Function to destroy the tree and free all memory used by nodes
void destroy_tree(Node* root) {
    if (root == NULL) return;  // Base case: empty node

    // Recursively destroy the left subtree
    destroy_tree(root->left);

    // Recursively destroy the right subtree
    destroy_tree(root->right);

    // Now that both subtrees are freed, free the current node
    free(root);
}

// In-order traversal to print the tree (left -> root -> right)
void print_in_order(Node* root) {
    if (root == NULL) return;

    print_in_order(root->left);           // Visit left child
    printf("%d ", root->data);            // Print current node
    print_in_order(root->right);          // Visit right child
}

// Main function to demonstrate tree creation and destruction
int main() {
    Node* root = NULL;  // Initialize an empty tree

    // Insert some values into the tree
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Tree (in-order): ");
    print_in_order(root);  // Print values in sorted order
    printf("\n");

    // Destroy the tree and free all memory
    destroy_tree(root);
    root = NULL;  // Set root to NULL to avoid dangling pointer

    printf("Tree destroyed.\n");

    return 0;
}

