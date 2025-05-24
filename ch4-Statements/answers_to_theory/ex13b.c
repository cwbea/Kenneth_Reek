#include <stdio.h>

int main(void)
{
    int choice;
    int which_word;
    
    do {
        printf("\tMenu\n");
        printf("1.\tNewspaper Report\n");
        printf("2.\tQuit\n");
        printf("\nEnter choice: ");
        scanf("%d", &choice);  // Read the menu choice

        if (choice == 1) {
            printf("\nEnter value for which_word (1 - 5): ");
            scanf("%d", &which_word);  // Read which_word only if choice is 1

            switch (which_word) {
                case 1:
                    printf("\nwho\n");
                    break;
                case 2:
                    printf("\nwhat\n");
                    break;
                case 3:
                    printf("\nwhen\n");
                    break;
                case 4:
                    printf("\nwhere\n");
                    break;
                case 5:
                    printf("\nwhy\n");
                    break;
                default:
                    printf("\ndon't know\n");
            }
        }

    } while (choice != 2);  // Exit when user chooses 2

    return 0;
}

