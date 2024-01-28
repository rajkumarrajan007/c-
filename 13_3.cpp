#include <iostream>
using namespace std;
int main() {
    try {
        // Simulate a runtime error
        throw logic_error("This is a logic error");

    } catch (const runtime_error& e) {
        // Catch block for runtime_error (and its derived classes)
        cerr << "Caught runtime_error: " << e.what() << endl;

    } catch (...) {
        // Catch block for any other type of exception not caught by the previous blocks
        cerr << "Caught unknown exception" <<endl;
    }

    return 0;
}
