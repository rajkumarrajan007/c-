#include <iostream>
#include <vector>
using namespace std;

class FloatVector {
private:
    vector<float> values;

public:
    // Member function to create the vector
    void createVector(const vector<float>& initialValues) {
        values = initialValues;
    }

    // Member function to modify the value of a given element
    void modifyElement(size_t index, float newValue) {
        if (index < values.size()) {
            values[index] = newValue;
            cout << "Element at index " << index << " modified successfully." << endl;
        } else {
            cout << "Invalid index. Modification failed." << endl;
        }
    }

    // Member function to multiply the vector by a scalar value
    void multiplyByScalar(float scalar) {
        for (float& value : values) {
            value *= scalar;
        }
        cout << "Vector multiplied by scalar successfully." << endl;
    }

    // Member function to display the vector
    void displayVector() const {
        cout << "Vector: (";
        for (size_t i = 0; i < values.size(); ++i) {
            cout << values[i];
            if (i < values.size() - 1) {
                cout << ", ";
            }
        }
        cout << ")" <<endl;
    }
};

int main() {
    FloatVector floatVec;

    // Create the vector
    vector<float> initialValues = {10.2, 20.5, 30.8, 40.1};
    floatVec.createVector(initialValues);

    // Display the initial vector
    cout << "Initial ";
    floatVec.displayVector();

    // Modify an element
    floatVec.modifyElement(2, 35.0);

    // Display the vector after modification
    cout << "After modification: ";
    floatVec.displayVector();

    // Multiply the vector by a scalar
    floatVec.multiplyByScalar(2.0);

    // Display the vector after multiplication
    cout << "After multiplication: ";
    floatVec.displayVector();

    return 0;
}
