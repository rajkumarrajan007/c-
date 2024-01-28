#include <iostream>
#include <iomanip>
using namespace std;

class Account {
protected:
    string customerName;
    int accountNumber;
    char accountType;
    double balance;

public:
    // Constructor for Account class
    Account(const string& name, int number, char type, double initialBalance)
        : customerName(name), accountNumber(number), accountType(type), balance(initialBalance) {}

    // Function to display account details and balance
    void displayBalance() const {
        cout << "Customer Name: " << customerName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Balance: $" << fixed << setprecision(2) << balance << endl;
    }

    // Function to accept deposit from a customer and update the balance
    void deposit() {
        double amount;
        cout << "Enter deposit amount: $";
        cin >> amount;

        balance += amount;
        cout << "Deposit successful. Updated balance: $" <<fixed <<setprecision(2) << balance <<endl;
    }

    // Virtual function to compute and deposit interest (to be overridden by derived classes)
    virtual void computeAndDepositInterest() = 0;

    // Function to permit withdrawal and update the balance
    void withdraw() {
        double amount;
        cout << "Enter withdrawal amount: $";
        cin >> amount;

        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrawal successful. Updated balance: $" <<fixed <<setprecision(2) << balance <<endl;
        } else {
            cout << "Insufficient funds for withdrawal." << endl;
        }
    }

    // Function to check for the minimum balance, impose penalty if necessary, and update the balance
    void checkMinimumBalance(double minimumBalance, double penalty) {
        if (balance < minimumBalance) {
            cout << "Balance is below the minimum required. A penalty of $" << penalty << " will be imposed." <<endl;
            balance -= penalty;
        }
    }
};

class CurrentAccount : public Account {
public:
    // Constructor for CurrentAccount class
    CurrentAccount(const string& name, int number, double initialBalance)
        : Account(name, number, 'C', initialBalance) {}

    // Override the virtual function to compute and deposit interest for CurrentAccount
    void computeAndDepositInterest() override {
        // Current accounts do not earn interest
        cout << "Interest not applicable for Current Account." <<endl;
    }

    // Function to check for the minimum balance and impose penalty if necessary
    void checkMinimumBalance() {
        // Assuming a minimum balance of $1000 and a penalty of $50 for Current Account
        Account::checkMinimumBalance(1000.0, 50.0);
    }
};

class SavingsAccount : public Account {
public:
    // Constructor for SavingsAccount class
    SavingsAccount(const string& name, int number, double initialBalance)
        : Account(name, number, 'S', initialBalance) {}

    // Override the virtual function to compute and deposit interest for SavingsAccount
    void computeAndDepositInterest() override {
        // Assuming a monthly interest rate of 1% for Savings Account
        double interest = balance * 0.01;
        balance += interest;
        cout << "Interest of $" <<fixed <<setprecision(2) << interest << " deposited. Updated balance: $" << balance <<endl;
    }

    // Function to check for the minimum balance and impose penalty if necessary
    void checkMinimumBalance() {
        // Assuming a minimum balance of $500 for Savings Account
        Account::checkMinimumBalance(500.0, 0.0);
    }
};

int main() {
    // Create objects of CurrentAccount and SavingsAccount using constructors
    CurrentAccount currentAccount("John Doe", 1001, 1500.0);
    SavingsAccount savingsAccount("Jane Smith", 2002, 800.0);

    // Display initial balances
    cout << "\nInitial Balances:" <<endl;
    currentAccount.displayBalance();
    savingsAccount.displayBalance();

    // Deposit, withdraw, compute interest, and check minimum balance for CurrentAccount
    cout << "\nOperations for Current Account:" <<endl;
    currentAccount.deposit();
    currentAccount.withdraw();
    currentAccount.computeAndDepositInterest();
    currentAccount.checkMinimumBalance();
    currentAccount.displayBalance();

    // Deposit, withdraw, compute interest, and check minimum balance for SavingsAccount
    cout << "\nOperations for Savings Account:" <<endl;
    savingsAccount.deposit();
    savingsAccount.withdraw();
    savingsAccount.computeAndDepositInterest();
    savingsAccount.checkMinimumBalance();
    savingsAccount.displayBalance();

    return 0;
}
