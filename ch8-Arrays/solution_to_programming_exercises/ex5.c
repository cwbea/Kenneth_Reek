#include <stdio.h>

// This function multiplies two matrices:
// m1 is the first matrix with x rows and y columns (dimensions: x × y)
// m2 is the second matrix with y rows and z columns (dimensions: y × z)
// r is the result matrix with x rows and z columns (dimensions: x × z)
void matrix_multiply(int *m1, int *m2, int *r, int x, int y, int z) {

    // Loop over each row 'i' of matrix m1 (first matrix)
    for (int i = 0; i < x; i++) {

        // Loop over each column 'j' of matrix m2 (second matrix)
        for (int j = 0; j < z; j++) {

            // Initialize the sum for r[i][j] (element of result matrix at row i and column j)
            int sum = 0;

            // Loop over each element 'k' in the shared dimension (y) to compute dot product
            for (int k = 0; k < y; k++) {

                // Multiply the element at row i, column k of m1
                // with the element at row k, column j of m2
                // and add the result to the running sum
                sum += m1[i * y + k] * m2[k * z + j];
                // Explanation:
                // m1[i * y + k] accesses element at row i, column k in matrix m1 (flattened)
                // m2[k * z + j] accesses element at row k, column j in matrix m2 (flattened)
            }

            // Store the computed sum into the result matrix at position (i, j)
            r[i * z + j] = sum;
            // Explanation:
            // r[i * z + j] accesses element at row i, column j in result matrix r (flattened)
        }
    }
}

