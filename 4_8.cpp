#include <iostream>
using namespace std;

// Function to calculate m^n, default value of n is 2 (for double)
double power(double m, int n = 2) {
    double result = 1.0;

    // Calculate m^n
    for (int i = 0; i < n; ++i) {
        result *= m;
    }

    return result;
}

// Overloaded function for int base
int power(int m, int n = 2) {
    int result = 1;

    // Calculate m^n
    for (int i = 0; i < n; ++i) {
        result *= m;
    }

    return result;
}

int main() {
    // Test with double base
    double baseDouble;
    int exponentDouble;

    cout << "Enter the double base (m): ";
    cin >> baseDouble;

    cout << "Enter the exponent (n, default is 2): ";
    cin >> exponentDouble;

    double resultDouble = power(baseDouble, exponentDouble);
    cout << "Double result: " << baseDouble << " raised to the power " << exponentDouble << " is: " << resultDouble <<endl;

    // Test with int base
    int baseInt;
    int exponentInt;

    cout << "\nEnter the int base (m): ";
    cin >> baseInt;

    cout << "Enter the exponent (n, default is 2): ";
    cin >> exponentInt;

    int resultInt = power(baseInt, exponentInt);
    cout << "Int result: " << baseInt << " raised to the power " << exponentInt << " is: " << resultInt << endl;

    return 0;
}
