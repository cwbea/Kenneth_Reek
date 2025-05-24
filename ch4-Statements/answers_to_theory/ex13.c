#include <stdio.h>

int main(void)
{
    int which_word;

    printf("Enter a number (1-5): ");
    scanf("%d", &which_word);

    switch (which_word) {
        case 1:
            printf("who\n");
            break;
        case 2:
            printf("what\n");
            break;
        case 3:
            printf("when\n");
            break;
        case 4:
            printf("where\n");
            break;
        case 5:
            printf("why\n");
            break;
        default:
            printf("don't know\n");
    }

    return 0;
}

