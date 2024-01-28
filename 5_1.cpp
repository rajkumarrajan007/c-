#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string depositorName;
    int accountNumber;
    string accountType;
    double balance;

public:
    // Member function to assign initial values
    void initializeAccount(const string& name, int accNumber, const string& accType, double initialBalance) {
        depositorName = name;
        accountNumber = accNumber;
        accountType = accType;
        balance = initialBalance;
    }

    // Member function to deposit an amount
    void deposit(double amount) {
        balance += amount;
        cout << "Amount deposited successfully. New balance: " << balance <<endl;
    }

    // Member function to withdraw an amount after checking the balance
    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Amount withdrawn successfully. New balance: " << balance <<endl;
        } else {
            cout << "Insufficient balance. Withdrawal failed." <<endl;
        }
    }

    // Member function to display name and balance
    void displayInfo() const {
        cout << "Account Holder: " << depositorName <<endl;
        cout << "Account Number: " << accountNumber <<endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Balance: " << balance <<endl;
    }
};

int main() {
    BankAccount account;

    // Initialize account
    account.initializeAccount("John Doe", 123456, "Savings", 1000.0);

    // Display initial info
    cout << "Initial Account Information:\n";
    account.displayInfo();

    // Deposit and display updated info
    account.deposit(500.0);
    account.displayInfo();

    // Withdraw and display updated info
    account.withdraw(200.0);
    account.displayInfo();

    // Attempt to withdraw more than the balance
    account.withdraw(10000.0);

    return 0;
}
