#include <iostream>
using namespace std;

int main() {
    try {
        int numerator, denominator, result;
        
        // Get user input for numerator
        cout << "Enter numerator: ";
        cin >> numerator;

        // Get user input for denominator
        cout << "Enter denominator: ";
        cin >> denominator;

        // Check if the denominator is zero
        if (denominator == 0) {
            throw runtime_error("Error: Division by zero is not allowed");
        }

        // Perform the division
        result = numerator / denominator;

        // Display the result
        cout << "Result: " << result << endl;

    } catch (const runtime_error& e) {
        // Catch block handles the exception
        cerr << e.what() << endl;
    }

    return 0;
}
