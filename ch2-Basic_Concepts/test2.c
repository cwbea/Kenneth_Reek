#include <stdio.h>

int main() {
    printf("Hello, World!\n");
    if (1) {
        printf("Brace test.\n");
    // <- Try removing this closing brace to test errors
    return 0;
}

