#include <iostream>
#include <string>
using namespace std;

// Base class: Person
class Person {
protected:
    string name;
    int code;

public:
    // Constructor for Person
    Person(const string& personName, int personCode)
        : name(personName), code(personCode) {}

    // Function to display information
    virtual void displayInfo() const {
        cout << "Name: " << name << endl;
        cout << "Code: " << code << endl;
    }
};

// Derived class: Account
class Account : virtual public Person {
protected:
    double pay;

public:
    // Constructor for Account
    Account(const string& accountName, int accountCode, double accountPay)
        : Person(accountName, accountCode), pay(accountPay) {}

    // Function to display information
    void displayInfo() const override {
        Person::displayInfo();
        cout << "Pay: $" << pay << endl;
    }
};

// Derived class: Admin
class Admin : virtual public Person {
protected:
    int experience;

public:
    // Constructor for Admin
    Admin(const std::string& adminName, int adminCode, int adminExperience)
        : Person(adminName, adminCode), experience(adminExperience) {}

    // Function to display information
    void displayInfo() const override {
        Person::displayInfo();
        cout << "Experience: " << experience << " years" << endl;
    }
};

// Derived class: Master
class Master : public Account, public Admin {
public:
    // Constructor for Master
    Master(const string& masterName, int masterCode, double masterPay, int masterExperience)
        : Person(masterName, masterCode), Account(masterName, masterCode, masterPay), Admin(masterName, masterCode, masterExperience) {}

    // Function to display information
    void displayInfo() const override {
        Person::displayInfo();
        cout << "Pay: $" << pay << endl;
        cout << "Experience: " << experience << " years" << endl;
    }
};

int main() {
    // Create instances of different classes
    Person person("John Doe", 101);
    Account account("Alice Smith", 201, 50000.0);
    Admin admin("Bob Johnson", 301, 10);
    Master master("Eva Williams", 401, 60000.0, 15);

    // Display information for each class
    cout << "\nPerson Information:\n";
    person.displayInfo();

    cout << "\nAccount Information:\n";
    account.displayInfo();

    cout << "\nAdmin Information:\n";
    admin.displayInfo();

    cout << "\nMaster Information:\n";
    master.displayInfo();

    return 0;
}
