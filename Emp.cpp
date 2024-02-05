#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Employee {
    string name;
    int employeeID;
    string designation;
    int experience;
    int age;
};

class EmployeeManagementSystem {
private:
    vector<Employee> employeeTable;

public:
    void insertEmployee() {
        Employee emp;
        cout << "Enter Employee Name: ";
        cin >> emp.name;
        cout << "Enter Employee ID: ";
        cin >> emp.employeeID;
        cout << "Enter Employee Designation: ";
        cin >> emp.designation;
        cout << "Enter Employee Experience: ";
        cin >> emp.experience;
        cout << "Enter Employee Age: ";
        cin >> emp.age;

        employeeTable.push_back(emp);
        cout << "Employee added successfully!" << endl;
    }

    void deleteEmployee(int empID) {
        auto it = find_if(employeeTable.begin(), employeeTable.end(), [empID](const Employee& emp) {
            return emp.employeeID == empID;
        });

        if (it != employeeTable.end()) {
            employeeTable.erase(it);
            cout << "Employee deleted successfully!" << endl;
        } else {
            cout << "Employee not found with ID: " << empID << endl;
        }
    }

    void searchEmployee(int empID) {
        auto it = find_if(employeeTable.begin(), employeeTable.end(), [empID](const Employee& emp) {
            return emp.employeeID == empID;
        });

        if (it != employeeTable.end()) {
            cout << "Employee found:" << endl;
            displayEmployee(*it);
        } else {
            cout << "Employee not found with ID: " << empID << endl;
        }
    }

    void displayEmployee(const Employee& emp) {
        cout << "Name: " << emp.name << endl;
        cout << "Employee ID: " << emp.employeeID << endl;
        cout << "Designation: " << emp.designation << endl;
        cout << "Experience: " << emp.experience << " years" << endl;
        cout << "Age: " << emp.age << " years" << endl;
    }
};

int main() {
    EmployeeManagementSystem ems;
    int choice, empID;

    do {
        cout << "\nEmployee Management System Menu:" << endl;
        cout << "1. Insert New Employee" << endl;
        cout << "2. Delete Employee" << endl;
        cout << "3. Search Employee" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                ems.insertEmployee();
                break;
            case 2:
                cout << "Enter Employee ID to delete: ";
                cin >> empID;
                ems.deleteEmployee(empID);
                break;
            case 3:
                cout << "Enter Employee ID to search: ";
                cin >> empID;
                ems.searchEmployee(empID);
                break;
            case 4:
                cout << "Exiting Employee Management System. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 4);

    return 0;
}
