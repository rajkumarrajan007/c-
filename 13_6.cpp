#include <iostream>
using namespace std;

void readNumbers(double& num1, double& num2) {
    cout << "Enter the first number: ";
    cin >> num1;

    if (cin.fail()) {
        throw invalid_argument("Invalid input. Please enter a valid double.");
    }

    cout << "Enter the second number: ";
    cin >> num2;

    if (cin.fail()) {
        throw invalid_argument("Invalid input. Please enter a valid double.");
    }
}

double calculateDivision(double num1, double num2) {
    if (num2 == 0.0) {
        throw runtime_error("Error: Division by zero is not allowed.");
    }

    return num1 / num2;
}

int main() {
    try {
        double number1, number2;

        readNumbers(number1, number2);

        double result = calculateDivision(number1, number2);

        cout << "Result of division: " << result << endl;

    } catch (const invalid_argument& e) {
        // Catch block for invalid input (non-double)
        cerr << "Invalid input: " << e.what() << endl;

    } catch (const runtime_error& e) {
        // Catch block for divide-by-zero condition
        cerr << e.what() << std::endl;
    }

    return 0;
}
