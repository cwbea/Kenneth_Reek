#include <stdio.h>     // for printf and scanf
#include <math.h>      // for sqrt() function

// Function to calculate wind chill based on temperature and wind speed
double wind_chill(double temp, double velocity) {
    // Constants provided by the wind chill formula
    const double A = 10.45;
    const double B = 10.0;
    const double C = -1.0;
    const double X = 1.78816; // This is 4 mph converted to m/s

    double delta_t = 33.0 - temp;  // At = skin temp (33°C) - air temperature

    // Wind chill formula (as provided)
    double numerator = (A + B * sqrt(velocity) + C * velocity) * delta_t;
    double denominator = (A + B * sqrt(X) + C * X);

    // Final wind chill temperature in Celsius
    return 33.0 - (numerator / denominator);
}

int main() {
    double temp, velocity;

    // Ask user for input
    printf("Enter the air temperature in Celsius: ");
    scanf("%lf", &temp); // Read double for temperature

    printf("Enter the wind speed in meters per second: ");
    scanf("%lf", &velocity); // Read double for wind speed

    // Calculate wind chill using the function
    double wc = wind_chill(temp, velocity);

    // Print result with 2 decimal places
    printf("The wind chill temperature is: %.2f°C\n", wc);

    return 0; // Return success
}

