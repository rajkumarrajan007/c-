#include <iostream>
#include <string>
using namespace std;

// Base class: Staff
class Staff {
protected:
    int code;
    string name;

public:
    // Constructor for Staff
    Staff(int staffCode, const string& staffName)
        : code(staffCode), name(staffName) {}

    // Function to display information
    virtual void displayInfo() const {
        cout << "Code: " << code << endl;
        cout << "Name: " << name << endl;
    }
};

// Derived class: Teacher
class Teacher {
private:
    Staff staff;
    string subject;
    string publication;

public:
    // Constructor for Teacher
    Teacher(int teacherCode, const string& teacherName, const string& subj, const string& pub)
        : staff(teacherCode, teacherName), subject(subj), publication(pub) {}

    // Function to display information
    void displayInfo() const {
        staff.displayInfo();
        cout << "Subject: " << subject << endl;
        cout << "Publication: " << publication << endl;
    }
};

// Derived class: Officer
class Officer {
private:
    Staff staff;
    string grade;

public:
    // Constructor for Officer
    Officer(int officerCode, const string& officerName, const string& officerGrade)
        : staff(officerCode, officerName), grade(officerGrade) {}

    // Function to display information
    void displayInfo() const {
        staff.displayInfo();
        cout << "Grade: " << grade << endl;
    }
};

// Derived class: Typist
class Typist {
private:
    Staff staff;
    int speed;

public:
    // Constructor for Typist
    Typist(int typistCode, const string& typistName, int typistSpeed)
        : staff(typistCode, typistName), speed(typistSpeed) {}

    // Function to display information
    void displayInfo() const {
        staff.displayInfo();
        cout << "Speed: " << speed << " words per minute" <<endl;
    }
};

int main() {
    // Create instances of different classes
    Teacher teacher(101, "John Doe", "Math", "Research in Education");
    Officer officer(201, "Alice Smith", "Grade A");
    Typist typist(301, "Bob Johnson", 70);

    // Display information for each class
    cout << "\nTeacher Information:\n";
    teacher.displayInfo();

    cout << "\nOfficer Information:\n";
    officer.displayInfo();

    cout << "\nTypist Information:\n";
    typist.displayInfo();

    return 0;
}
