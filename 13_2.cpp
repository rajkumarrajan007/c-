#include <iostream>
//#include <stdexcept>
using namespace std;

int main() {
    try {
        // Simulate a runtime error
        throw runtime_error("This is a runtime error");

    } catch (const logic_error& e) {
        // Catch block for logic_error (and its derived classes)
        cerr << "Caught logic_error: " << e.what() << endl;

    } catch (const runtime_error& e) {
        // Catch block for runtime_error (and its derived classes)
        cerr << "Caught runtime_error: " << e.what() << endl;

    } catch (const exception& e) {
        // Catch block for any other exception derived from std::exception
        cerr << "Caught exception: " << e.what() << endl;

    } catch (...) {
        // Catch block for any other type of exception not derived from std::exception
        cerr << "Caught unknown exception" << endl;
    }

    return 0;
}
