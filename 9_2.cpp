#include <iostream>
#include <cmath> // for the M_PI constant
using namespace std;

// Base class Shape
class Shape {
protected:
    double side1;
    double side2;

public:
    // Member function to initialize base class data members
    void getData(double side1, double side2 = 0) {
        this->side1 = side1;
        this->side2 = side2;
    }

    // Virtual member function to compute and display the area
    virtual void displayArea() {
        cout << "Area: ";
    }
};

class Triangle : public Shape {
public:
    // Redefine displayArea() 
    void displayArea() override {
        Shape::displayArea();
        double area = 0.5 * side1 * side2;
        cout << area << endl;
    }
};

class Rectangle : public Shape {
public:
    // Redefine 
    void displayArea() override {
        Shape::displayArea();
        double area = side1 * side2;
        cout << area <<endl;
    }
};

// Derived class Circle
class Circle : public Shape {
public:
    // Redefine 
    void displayArea() override {
        Shape::displayArea();
        double area = M_PI *pow(side1, 2);
        cout << area << endl;
    }
};

int main() {
    // Create objects of Triangle, Rectangle, and Circle
    Triangle triangle;
    Rectangle rectangle;
    Circle circle;

    // Get data and display area for Triangle
    cout << "Enter dimensions for Triangle:" << std::endl;
    triangle.getData(4, 8); 
    triangle.displayArea();

    // Get data and display area for Rectangle
    cout << "Enter dimensions for Rectangle:" <<endl;
    rectangle.getData(5, 10);
    rectangle.displayArea();

    // Get data and display area for Circle
    cout << "Enter radius for Circle:" <<endl;
    circle.getData(3); // Pass only one value for the circle
    circle.displayArea();

    return 0;
}
