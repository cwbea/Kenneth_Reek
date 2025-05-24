#include <stdio.h>

void copy_n(char dst[], char src[], int n) {
    int i = 0;

    // Copy characters from src to dst until src ends or n is reached
    while (i < n && src[i] != '\0') {
        dst[i] = src[i];
        i++;
    }

    // Fill the rest with '\0' if src is shorter than n
    while (i < n) {
        dst[i] = '\0';
        i++;
    }
}

