/*
** Function: search_list
** Purpose: Search for a specific value in a singly linked list.
** Parameters:
**   - node: Pointer to the first node in the list (head of the list).
**   - value: Pointer to the value we're searching for.
**   - compare: Function pointer to a comparison function, which takes
**     two `void const *` values and returns 0 if they are equal.
** Returns:
**   - Pointer to the node that contains the matching value,
**     or NULL if the value is not found in the list.
*/

#include <stdio.h>      // For standard input/output functions (optional in this case)
#include "node.h"       // Contains the definition of the Node structure

// Definition of the search function
Node *search_list(Node *node, void const *value,
                  int (*compare)(void const *, void const *))
{
    // Loop through the linked list until we reach the end (node == NULL)
    while (node != NULL) {
        // Use the compare function to check if the current node's value matches the target value
        // &node->value passes the address of the node's value field
        if (compare(&node->value, value) == 0)
            break;  // Match found, exit the loop

        // Move to the next node in the list
        node = node->link;
    }

    // Return the node that matches the value, or NULL if not found
    return node;
}



int compare_ints( void const *a, void const *b )
{

	if( *(int *)a == *(int *)b )
	return 0;
	else
	return 1;
}

//calling the function
desired_node = search_list( root, &desired_value,
compare_ints );

//if you decided to search for a list of strings
...
desired_node = search_list( root, "desired_value",
strcmp );
