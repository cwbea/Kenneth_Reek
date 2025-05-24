/*
** Add the new node to the list.
*/

// Point the new node forward to the next node in the list
newnode->fwd = next;

if (this != rootp) {
    // Case: inserting after an existing node (not at front)
    this->fwd = newnode;       // Link the previous node to the new node
    newnode->bwd = this;       // Link the new node back to the previous node
} else {
    // Case: inserting at the front of the list
    rootp->fwd = newnode;      // Root now points forward to the new node
    newnode->bwd = NULL;       // No node before new node
}

// Handle the node after the new node
if (next != NULL) {
    // Case: inserting before a node (not at end)
    next->bwd = newnode;       // Link next node back to new node
} else {
    // Case: inserting at end of list
    rootp->bwd = newnode;      // Root's back pointer updated to new last node
}

