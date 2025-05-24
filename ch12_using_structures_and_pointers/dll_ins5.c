/*insert function using conditional expressions
** Add the new node to the list.
*/

// Set the new node's forward link to point to the next node
newnode->fwd = next;

// Link the current node (this) to the new node
this->fwd = newnode;

// If 'this' is not the dummy root, set new node's backward link to 'this'
// Otherwise, set it to NULL (new node becomes the first actual data node)
newnode->bwd = (this != rootp) ? this : NULL;

// If 'next' is not NULL, point its backward link to the new node
// Otherwise, update rootp->bwd to point to the new node (it’s now the last node)
(next != NULL ? next : rootp)->bwd = newnode;

