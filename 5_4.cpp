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
            cout << "Element at index " << index << " modified successfully." <<endl;
        } else {
            cout << "Invalid index. Modification failed." <<endl;
        }
    }

    // Member function to multiply the vector by a scalar value
    void multiplyByScalar(float scalar) {
        for (float& value : values) {
            value *= scalar;
        }
        cout << "Vector multiplied by scalar successfully." <<endl;
    }

    // Member function to add two vectors
    FloatVector addVectors(const FloatVector& otherVector) const {
        FloatVector resultVector;
        resultVector.values.resize(std::min(values.size(), otherVector.values.size()));

        for (size_t i = 0; i < resultVector.values.size(); ++i) {
            resultVector.values[i] = values[i] + otherVector.values[i];
        }

        return resultVector;
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
        cout << ")" << endl;
    }
};

int main() {
    FloatVector vector1, vector2, resultVector;

    // Create the first vector
    vector1.createVector({10.2, 20.5, 30.8, 40.1});
    cout << "Vector 1: ";
    vector1.displayVector();

    // Create the second vector
    vector2.createVector({5.0, 10.0, 15.0, 20.0});
    cout << "Vector 2: ";
    vector2.displayVector();

    // Add the vectors
    resultVector = vector1.addVectors(vector2);
    cout << "Resultant Vector: ";
    resultVector.displayVector();

    return 0;
}
