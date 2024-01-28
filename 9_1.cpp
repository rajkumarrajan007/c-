#include <iostream>
using namespace std;

// Base class Shape
class Shape {
protected:
    double side1;
    double side2;

public:
    // Member function to initialize base class data members
    void getData() {
        cout << "Enter the dimensions:" <<endl;
        cout << "Side 1: ";
        cin >> side1;
        cout << "Side 2: ";
        cin >> side2;
    }

    // Virtual member function to compute and display the area
    virtual void displayArea() {
        cout << "Area: ";
    }
};

// Derived class Triangle
class Triangle : public Shape {
public:
    // Redefine the displayArea() function for triangles
    void displayArea() override {
        Shape::displayArea();
        double area = 0.5 * side1 * side2;
        cout << area << std::endl;
    }
};

// Derived class Rectangle
class Rectangle : public Shape {
public:
    // Redefine the displayArea() function for rectangles
    void displayArea() override {
        Shape::displayArea();
        double area = side1 * side2;
        cout << area << std::endl;
    }
};

int main() {
    // Create objects of Triangle and Rectangle
    Triangle triangle;
    Rectangle rectangle;

    // Get data and display area for Triangle
    cout << "Enter dimensions for Triangle:" <<endl;
    triangle.getData();
    triangle.displayArea();

    // Get data and display area for Rectangle
    cout << "Enter dimensions for Rectangle:" << endl;
    rectangle.getData();
    rectangle.displayArea();

    return 0;
}
