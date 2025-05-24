typedef struct concordance_node {
    char *word;                        // The word itself
    struct concordance_node *next;     // Pointer to the next node in the list
    struct concordance_node *secondary; // Pointer to a secondary list of words starting with the same letter
} ConcordanceNode;

