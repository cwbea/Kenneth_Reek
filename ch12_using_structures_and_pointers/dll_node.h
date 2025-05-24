typedef struct NODE {
    struct NODE *fwd;   // Pointer to the next node (forward link)
    struct NODE *bwd;   // Pointer to the previous node (backward link)
    int value;          // Data held in the node
} Node;

