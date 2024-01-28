#include <iostream>
#include <cstring>
using namespace std;

class String {
private:
    char* str;
    int length;

public:
    // Default constructor for uninitialized string
    String() : str(nullptr), length(0) {}

    // Constructor to initialize with a string constant
    String(const char* s) {
        length = strlen(s);
        str = new char[length + 1];
        strcpy(str, s);
    }

    // Destructor to free allocated memory
    ~String() {
        delete[] str;
    }

    // Function to concatenate two strings and return a new string
    String operator+(const String& other) const {
        String result;
        result.length = length + other.length;
        result.str = new char[result.length + 1];
        strcpy(result.str, str);
        strcat(result.str, other.str);
        return result;
    }

    // Function to copy one string to another
    String& operator=(const String& other) {
        if (this != &other) {
            delete[] str;
            length = other.length;
            str = new char[length + 1];
            std::strcpy(str, other.str);
        }
        return *this;
    }

    // Function to display the string
    void display() const {
        cout << str << endl;
    }
};

int main() {
    // Create uninitialized string objects
    String s1;

    // Create objects with string constants
    String s2("Well done!");
    String s3(" Good job!");

    // Concatenate two strings
    String result = s2 + s3;

    // Display the strings
    cout << "s1: ";
    s1.display();

    cout << "s2: ";
    s2.display();

    cout << "s3: ";
    s3.display();

    cout << "Concatenated Result (s2 + s3): ";
    result.display();

    // Copy one string to another
    String s4 = s2;

    cout << "Copied Result (s4 = s2): ";
    s4.display();

    return 0;
}
