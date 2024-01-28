#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Base class: Staff
class Staff {
protected:
    int code;
    string name;

public:
    // Constructor
    Staff(int staffCode, const string& staffName)
        : code(staffCode), name(staffName) {}

    // Virtual function to display information
    virtual void displayInfo() const {
        cout << "Code: " << code <<endl;
        cout << "Name: " << name <<endl;
    }
};

// Derived class: Teacher
class Teacher : public Staff {
protected:
    string subject;
    string publication;

public:
    // Constructor
    Teacher(int teacherCode, const string& teacherName, const string& subj, const string& pub)
        : Staff(teacherCode, teacherName), subject(subj), publication(pub) {}

    // Override displayInfo for Teacher
    void displayInfo() const override {
        Staff::displayInfo();
        cout << "Subject: " << subject <<endl;
        cout << "Publication: " << publication <<endl;
    }
};

// Derived class: Officer
class Officer : public Staff {
protected:
    string grade;

public:
    // Constructor
    Officer(int officerCode, const string& officerName, const string& officerGrade)
        : Staff(officerCode, officerName), grade(officerGrade) {}

    // Override displayInfo for Officer
    void displayInfo() const override {
        Staff::displayInfo();
        cout << "Grade: " << grade <<endl;
    }
};

// Derived class: Typist
class Typist : public Staff {
protected:
    int speed;

public:
    // Constructor
    Typist(int typistCode, const string& typistName, int typistSpeed)
        : Staff(typistCode, typistName), speed(typistSpeed) {}

    // Override displayInfo for Typist
    void displayInfo() const override {
        Staff::displayInfo();
        cout << "Speed: " << speed << " words per minute" <<endl;
    }
};

// Derived class: Regular
class Regular : public Typist {
public:
    // Constructor
    Regular(int regularCode, const string& regularName, int regularSpeed)
        : Typist(regularCode, regularName, regularSpeed) {}
};

// Derived class: Casual
class Casual : public Typist {
protected:
    double dailyWages;

public:
    // Constructor
    Casual(int casualCode, const string& casualName, int casualSpeed, double wages)
        : Typist(casualCode, casualName, casualSpeed), dailyWages(wages) {}

    // Override displayInfo for Casual
    void displayInfo() const override {
        Typist::displayInfo();
        cout << "Daily Wages: $" << dailyWages <<endl;
    }
};

// Function to create the database and display information
void createDatabaseAndDisplayInfo(const vector<Staff*>& employees) {
    for (const auto& employee : employees) {
        cout << "\nEmployee Information:\n";
        employee->displayInfo();
    }
}

int main() {
    // Create instances of different employees
    Teacher teacher(101, "John Doe", "Math", "Research in Education");
    Officer officer(201, "Alice Smith", "Grade A");
    Regular regular(301, "Bob Johnson", 70);
    Casual casual(401, "Eva Williams", 60, 150.0);

    // Store pointers to employees in a vector
     vector<Staff*> employees;
    employees.push_back(&teacher);
    employees.push_back(&officer);
    employees.push_back(&regular);
    employees.push_back(&casual);

    // Create the database and display information
    createDatabaseAndDisplayInfo(employees);

    return 0;
}
