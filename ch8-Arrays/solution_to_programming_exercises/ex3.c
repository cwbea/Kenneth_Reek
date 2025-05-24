#include <stdbool.h>

// Function to check if a 10x10 matrix is an identity matrix
bool identity_matrix(int matrix[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i == j) {
                // Diagonal elements must be 1
                if (matrix[i][j] != 1) {
                    return false;
                }
            } else {
                // Off-diagonal elements must be 0
                if (matrix[i][j] != 0) {
                    return false;
                }
            }
        }
    }
    return true;
}

