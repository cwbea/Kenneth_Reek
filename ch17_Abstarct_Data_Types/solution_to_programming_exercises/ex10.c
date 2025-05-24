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
    Node* new_node = (Node*)malloc(sizeof(Node));  // Allocate memory for new node
    new_node->data = value;     // Set the node's data
    new_node->left = NULL;      // Set left child to NULL
    new_node->right = NULL;     // Set right child to NULL
    return new_node;
}

// Function to insert a value into the BST
Node* insert(Node* root, int value) {
    if (root == NULL) {
        // Tree is empty, so create and return a new node
        return create_node(value);
    }

    if (value < root->data) {
        // Recur on left subtree if value is less than root
        root->left = insert(root->left, value);
    } else {
        // Recur on right subtree if value is greater or equal
        root->right = insert(root->right, value);
    }

    return root;  // Return unchanged root pointer
}

// Function to find the minimum value node in a subtree
Node* find_min(Node* root) {
    while (root->left != NULL) {
        root = root->left;  // Keep going left to find minimum
    }
    return root;
}

// Function to delete a value from the BST
Node* delete_value(Node* root, int value) {
    if (root == NULL) {
        // Value not found, abort the program
        printf("Value %d not found in the tree. Aborting.\n", value);
        exit(EXIT_FAILURE);
    }

    if (value < root->data) {
        // Recur on left subtree if value is smaller
        root->left = delete_value(root->left, value);
    } else if (value > root->data) {
        // Recur on right subtree if value is larger
        root->right = delete_value(root->right, value);
    } else {
        // Node to delete found

        // Case 1: No child (leaf node)
        if (root->left == NULL && root->right == NULL) {
            free(root);      // Free memory
            return NULL;     // Return NULL to parent
        }
        // Case 2: One child (right only)
        else if (root->left == NULL) {
            Node* temp = root->right;
            free(root);      // Free current node
            return temp;     // Return right child to parent
        }
        // Case 2: One child (left only)
        else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);      // Free current node
            return temp;     // Return left child to parent
        }
        // Case 3: Two children
        else {
            Node* min_node = find_min(root->right);  // Get in-order successor
            root->data = min_node->data;             // Copy successor's value
            root->right = delete_value(root->right, min_node->data);  // Delete successor
        }
    }

    return root;  // Return updated root
}

// Function to print the BST in in-order traversal
void print_in_order(Node* root) {
    if (root == NULL) return;

    print_in_order(root->left);         // Left child
    printf("%d ", root->data);          // Current node
    print_in_order(root->right);        // Right child
}

// Main function to demonstrate insert, delete, and print
int main() {
    Node* root = NULL;

    // Insert some values into the tree
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Tree (in-order) before deletion: ");
    print_in_order(root);  // Display sorted tree
    printf("\n");

    // Delete a value from the tree
    root = delete_value(root, 70);

    printf("Tree (in-order) after deleting 70: ");
    print_in_order(root);  // Tree after deletion
    printf("\n");

    return 0;
}

