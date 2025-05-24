#include <stdio.h>
#include <stdbool.h>

int main(void) {
    bool precipitating;
    int temperature;

    // Simulate input
    printf("Is it precipitating? (1 for yes, 0 for no): ");
    scanf("%d", &precipitating);
    printf("Enter temperature in Fahrenheit: ");
    scanf("%d", &temperature);

    if (precipitating) {
        if (temperature < 32) {
            printf("snowing\n");
        } else {
            printf("raining\n");
        }
    } else {
        if (temperature < 60) {
            printf("cold\n");
        } else {
            printf("warm\n");
        }
    }

    return 0;
}

