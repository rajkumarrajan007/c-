#include <iostream>
using namespace std;

// Function to calculate m^n, default value of n is 2
double power(double m, int n = 2) {
    double result = 1.0;

    // Calculate m^n
    for (int i = 0; i < n; ++i) {
        result *= m;
    }

    return result;
}

int main() {
    double base;
    int exponent;

    // Get input from the user
    cout << "Enter the base (m): ";
    cin >> base;

    cout << "Enter the exponent (n, default is 2): ";
    cin >> exponent;

    // Call the power function
    double result = power(base, exponent);

    // Display the result
    cout << base << " raised to the power " << exponent << " is: " << result <<endl;

    return 0;
}
