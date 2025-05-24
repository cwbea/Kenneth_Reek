#include <stdio.h>

// Declare and initialize the array
unsigned char char_values[3][6][4][5] = {
    [1][2][2][3] = 'A',      // Location 1,2,2,3
    [2][4][3][2] = '3',      // Location 2,4,3,2
    [2][4][3][3] = 3,        // Location 2,4,3,3
    [2][1][1][2] = 0320,     // Location 2,1,1,2 (octal)

    [1][1][1][1] = ' ',      // Location 1,1,1,1
    [1][4][2][3] = '\n',     // Location 1,4,2,3
    [2][5][3][4] = 125,      // Location 2,5,3,4
    [2][2][2][2] = '\'',     // Location 2,2,2,2

    [1][3][2][2] = 0xf3,     // Location 1,3,2,2
    [2][2][3][1] = '\121',   // Location 2,2,3,1 (octal 121 = 'Q')
    [1][2][3][4] = 'x',      // Location 1,2,3,4
    [2][2][1][1] = '0',      // Location 2,2,1,1
};

// Optional: A function to print values for testing (not required by the prompt)
void print_non_zero_values(void) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 6; j++)
            for (int k = 0; k < 4; k++)
                for (int l = 0; l < 5; l++)
                    if (char_values[i][j][k][l] != 0)
                        printf("char_values[%d][%d][%d][%d] = 0x%02X\n",
                               i, j, k, l, char_values[i][j][k][l]);
}

int main(void) {
    print_non_zero_values(); //uncomment to verify non-zero values 
    return 0;
}

						
