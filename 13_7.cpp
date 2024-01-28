#include <iostream>
using namespace std;

double deepNestedFunction(double num) {
    if (num < 0) {
        throw out_of_range("Negative number is not allowed");
    }

    double result = num * 2.0;

    return result;
}

double middleLevelFunction(double num) {
    try {
        double result = deepNestedFunction(num);

        result += 10.0;

        return result;

    } catch (const out_of_range& e) {
        cerr << "Caught out_of_range exception in middleLevelFunction: " << e.what() << std::endl;

        // Rethrow the exception for further handling
        throw;
    }
}

void topLevelFunction(double num) {
    try {
        double result = middleLevelFunction(num);

        result /= 2.0;

        cout << "Final result: " << result << endl;

    } catch (const exception& e) {
        cerr << "Caught exception in topLevelFunction: " << e.what() << endl;
    }
}

int main() {
    try {
        double userInput;
        cout << "Enter a non-negative number: ";
        cin >> userInput;

        topLevelFunction(userInput);

    } catch (const exception& e) {
        // Catch block handling any exception thrown in the main program
        cerr << "Caught exception in main: " << e.what() << endl;
    }

    return 0;
}
