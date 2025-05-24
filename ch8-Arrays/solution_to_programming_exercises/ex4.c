#include <stdbool.h>

// Function to check if a flattened n x n matrix is an identity matrix
bool identity_matrix(const int *matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int value = matrix[i * size + j];  // Flattened 2D access
            if (i == j) {
                if (value != 1) {
                    return false;
                }
            } else {
                if (value != 0) {
                    return false;
                }
            }
        }
    }
    return true;
}

