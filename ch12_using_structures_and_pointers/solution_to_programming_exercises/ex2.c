

#include "singly_linked_list_node.h"  // Include the node definition

// Function to find a node with a given value in an unordered singly linked list
Node* find_node(Node* head, int target_value) {
    Node* current = head;  // Start from the beginning of the list

    // Traverse the list until we find the target value or reach the end
    while (current != NULL) {
        if (current->value == target_value) {
            return current;  // Found the node; return pointer to it
        }
        current = current->link;  // Move to the next node
    }

    return NULL;  // Target value not found in the list
}


   Explanation:

    Node* head: Pointer to the first node in the list.

    int target_value: The value you are searching for.

    The function loops through the list checking each node’s value.

    If the value matches, it returns a pointer to that node.

    If the end of the list is reached without finding it, it returns NULL.

⚙️ Adapting for an Ordered Singly Linked List

If the list is ordered (ascending), you can optimize the search by stopping early:

while (current != NULL && current->value <= target_value) {
    if (current->value == target_value) {
        return current;
    }
    current = current->link;
}

This stops the loop once current->value > target_value, which is not possible in unordered lists.
