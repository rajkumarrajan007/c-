#include <iostream>
using namespace std;

class DB; // Forward declaration for friend function

class DM {
private:
    int meters;
    int centimeters;

public:
    // Constructor to initialize DM object
    DM(int m, int cm) : meters(m), centimeters(cm) {}

    // Friend function for addition with DB
    friend DM addDMAndDB(const DM& dm, const DB& db);

    // Member function to display distance in meters and centimeters
    void display() const {
        cout << "Distance: " << meters << " meters and " << centimeters << " centimeters\n";
    }
};

class DB {
private:
    int feet;
    int inches;

public:
    // Constructor to initialize DB object
    DB(int ft, int in) : feet(ft), inches(in) {}

    // Friend function for addition with DM
    friend DM addDMAndDB(const DM& dm, const DB& db);

    // Member function to display distance in feet and inches
    void display() const {
        cout << "Distance: " << feet << " feet and " << inches << " inches\n";
    }
};

// Friend function definition for addition with DM
DM addDMAndDB(const DM& dm, const DB& db) {
    // Convert DB to equivalent DM (1 foot = 0.3048 meters, 1 inch = 0.0254 meters)
    int totalMeters = dm.meters + static_cast<int>(db.feet * 0.3048) + static_cast<int>(db.inches * 0.0254);
    int totalCentimeters = dm.centimeters + static_cast<int>((db.feet * 0.3048 - static_cast<int>(db.feet * 0.3048)) * 100) +
                           static_cast<int>((db.inches * 0.0254 - static_cast<int>(db.inches * 0.0254)) * 100);

    // Adjust for overflow
    if (totalCentimeters >= 100) {
        totalMeters += totalCentimeters / 100;
        totalCentimeters %= 100;
    }

    return DM(totalMeters, totalCentimeters);
}

int main() {
    // Create objects of DM and DB
    DM dmObj(5, 60); // 5 meters and 60 centimeters
    DB dbObj(3, 6);  // 3 feet and 6 inches

    // Display original distances
    cout << "Original Distances:\n";
    cout << "DM Object - ";
    dmObj.display();
    cout << "DB Object - ";
    dbObj.display();

    // Add DM and DB using friend function
    DM result = addDMAndDB(dmObj, dbObj);

    // Display result
    cout << "\nResultant Distance:\n";
    result.display();

    return 0;
}
