#include <stdio.h>     // For printf
#include <stdlib.h>    // For exit and EXIT_FAILURE
#include <stdbool.h>   // For using boolean types (not used here but good habit)

#define MAX_TREE_SIZE 100  // Define the maximum size of the tree array
#define EMPTY -1           // Special value to represent an empty spot in the tree

// Global array to represent the binary tree
int tree[MAX_TREE_SIZE];

// Function to initialize the tree by setting every index to EMPTY
void init_tree() {
    for (int i = 0; i < MAX_TREE_SIZE; i++) {
        tree[i] = EMPTY;
    }
}

// Function to insert a value into the tree
// Parameters: int value – the value to insert
void insert(int value) {
    int index = 0;  // Start at the root node (index 0)

    while (index < MAX_TREE_SIZE) {
        if (tree[index] == EMPTY) {
            tree[index] = value;  // Found empty spot, insert here
            return;
        } else if (value < tree[index]) {
            index = 2 * index + 1;  // Move to left child if value is smaller
        } else {
            index = 2 * index + 2;  // Move to right child if value is larger or equal
        }
    }

    // If no spot found, tree is full
    printf("Tree is full. Cannot insert %d\n", value);
}

// Helper function to find the minimum value index in the right subtree
// Parameters: int index – index of the subtree root
// Returns the index of the smallest value node in that subtree
int find_min_index(int index) {
    while (2 * index + 1 < MAX_TREE_SIZE && tree[2 * index + 1] != EMPTY) {
        index = 2 * index + 1;  // Keep moving to the left child
    }
    return index;
}

// Function to delete a value from the tree
// Parameters:
// - index: current index in the tree to search
// - value: the value to delete
void delete_value(int index, int value) {
    if (index >= MAX_TREE_SIZE || tree[index] == EMPTY) {
        // If index is out of range or node is empty, value not found
        printf("Value %d not found in the tree. Aborting.\n", value);
        exit(EXIT_FAILURE);  // Abort program
    }

    if (value < tree[index]) {
        // Recur on the left child if value is smaller
        delete_value(2 * index + 1, value);
    } else if (value > tree[index]) {
        // Recur on the right child if value is greater
        delete_value(2 * index + 2, value);
    } else {
        // Found the node to delete
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        // Case 1: No children
        if ((left >= MAX_TREE_SIZE || tree[left] == EMPTY) &&
            (right >= MAX_TREE_SIZE || tree[right] == EMPTY)) {
            tree[index] = EMPTY;  // Just delete the node
        }
        // Case 2: One child (only right)
        else if (left >= MAX_TREE_SIZE || tree[left] == EMPTY) {
            tree[index] = tree[right];  // Copy right child to current
            delete_value(right, tree[right]);  // Recursively delete copied node
        }
        // Case 2: One child (only left)
        else if (right >= MAX_TREE_SIZE || tree[right] == EMPTY) {
            tree[index] = tree[left];  // Copy left child to current
            delete_value(left, tree[left]);  // Recursively delete copied node
        }
        // Case 3: Two children
        else {
            int min_index = find_min_index(right);  // Find smallest in right subtree
            tree[index] = tree[min_index];          // Replace current with successor
            delete_value(min_index, tree[min_index]);  // Recursively delete successor
        }
    }
}

// Recursive function to print the tree in in-order traversal
// Parameters: index – current index to print from
void print_in_order(int index) {
    if (index >= MAX_TREE_SIZE || tree[index] == EMPTY) return;

    print_in_order(2 * index + 1);       // Visit left child
    printf("%d ", tree[index]);          // Print current node
    print_in_order(2 * index + 2);       // Visit right child
}

// Main function – entry point of the program
int main() {
    init_tree();  // Initialize the tree to all EMPTY values

    // Insert several values to form a binary search tree
    insert(50);
    insert(30);
    insert(70);
    insert(20);
    insert(40);
    insert(60);
    insert(80);

    // Display the tree using in-order traversal before deletion
    printf("Tree (in-order) before deletion: ");
    print_in_order(0);  // Start from the root node
    printf("\n");

    // Delete the value 70 from the tree
    delete_value(0, 70);

    // Display the tree using in-order traversal after deletion
    printf("Tree (in-order) after deleting 70: ");
    print_in_order(0);  // Start from the root node
    printf("\n");

    return 0;  // Indicate successful execution
}

