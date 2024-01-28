#include <iostream>
using namespace std;
// Function with throw specification allowing only std::logic_error
void functionWithThrowSpecification() throw(logic_error) {
    // This is allowed
    throw logic_error("This is a logic error");
}

void anotherFunctionWithThrowSpecification() throw(runtime_error) {
    // This is allowed
    throw runtime_error("This is a runtime error");
    
    // Uncommenting the line below would result in a compile-time error
    // throw std::logic_error("This is a logic error");
}

int main() {
    try {
        functionWithThrowSpecification();

    } catch (const exception& e) {
        // Catch block for any exception derived from std::exception
        cerr << "Caught exception: " << e.what() << endl;
    }

    try {
        anotherFunctionWithThrowSpecification();

    } catch (const exception& e) {
        // Catch block for any exception derived from std::exception
        cerr << "Caught exception: " << e.what() << endl;
    }

    return 0;
}
