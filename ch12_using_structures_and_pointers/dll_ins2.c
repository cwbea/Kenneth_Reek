/*
** Add the new node to the list.
*/
if (next != NULL) {
    /*
    ** Case 1 or 2: Inserting before a node (not at end of list)
    */
    newnode->fwd = next;        // New node points forward to 'next'
    next->bwd = newnode;        // 'Next' points back to new node

    if (this != rootp) {
        /* Case 1: Inserting in the middle of the list */
        this->fwd = newnode;    // Previous node points forward to new node
        newnode->bwd = this;    // New node points back to previous node
    } else {
        /* Case 2: Inserting at the very front (after root) */
        rootp->fwd = newnode;   // Root points forward to new node
        newnode->bwd = NULL;    // New node has no previous node
    }
} else {
    /*
    ** Case 3 or 4: Inserting at the end of the list
    */
    newnode->fwd = NULL;        // New node has no next node

    if (this != rootp) {
        /* Case 3: Inserting at end, but not the first node */
        this->fwd = newnode;    // Previous node points to new node
        newnode->bwd = this;    // New node points back to previous node
    } else {
        /* Case 4: List was empty, new node is first and last */
        rootp->fwd = newnode;   // Root points forward to new node
        newnode->bwd = NULL;    // New node has no previous node
    }

    rootp->bwd = newnode;       // Root's backward pointer points to the last node
}

