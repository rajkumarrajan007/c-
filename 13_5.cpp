#include <iostream>
using namespace std;
void processNumber(int num) {
    try {
        if (num < 0) {
            throw invalid_argument("Number must be non-negative");
        }

        // Some processing with the number
        cout << "Processing the number: " << num << endl;

    } catch (const invalid_argument& e) {
        // Catch block handling the exception locally
        cerr << "Caught exception locally: " << e.what() << endl;

        // Rethrow the exception for further handling
        throw;  // This rethrows the same exception that was caught
    }
}

int main() {
    try {
        int userInput;
        cout << "Enter a non-negative number: ";
        cin >> userInput;

        processNumber(userInput);

    } catch (const invalid_argument& e) {
        // Catch block handling the rethrown exception
        cerr << "Caught rethrown exception in main: " << e.what() <<  endl;
    }

    return 0;
}
