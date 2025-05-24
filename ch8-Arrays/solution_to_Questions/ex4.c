#include <stdio.h>
#include <string.h>

#define SIZE 100

int main() {
    char buffer[SIZE] = "madam";  // Example input string
    char *front, *rear;

    front = buffer;
    rear = buffer + strlen(buffer) - 1;

    while (front < rear) {
        if (*front != *rear)
            break;
        front++;
        rear--;
    }

    if (front >= rear) {
        printf("It is a palindrome!\n");
    } else {
        printf("It is not a palindrome.\n");
    }

    return 0;
}

