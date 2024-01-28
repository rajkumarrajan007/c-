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
    // Function to initialize account details
    void initializeAccount() {
        cout << "Enter customer name: ";
        cin.ignore(); // Ignore newline left in buffer by previous input
        getline(cin, customerName);

        cout << "Enter account number: ";
        cin >> accountNumber;

        cout << "Enter account type (S for Savings, C for Current): ";
        cin >> accountType;

        cout << "Enter initial balance: ";
        cin >> balance;
    }

    // Function to display account details and balance
    void displayBalance() {
        cout << "Customer Name: " << customerName << endl;
        cout << "Account Number: " << accountNumber <<endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Balance: $" << fixed << setprecision(2) << balance <<endl;
    }

    // Function to accept deposit from a customer and update the balance
    void deposit() {
        double amount;
        cout << "Enter deposit amount: $";
        cin >> amount;

        balance += amount;
        cout << "Deposit successful. Updated balance: $" << fixed <<setprecision(2) << balance <<endl;
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
            cout << "Withdrawal successful. Updated balance: $" << fixed <<setprecision(2) << balance <<endl;
        } else {
            cout << "Insufficient funds for withdrawal." <<endl;
        }
    }

    // Function to check for the minimum balance, impose penalty if necessary, and update the balance
    void checkMinimumBalance(double minimumBalance, double penalty) {
        if (balance < minimumBalance) {
            cout << "Balance is below the minimum required. A penalty of $" << penalty << " will be imposed." << endl;
            balance -= penalty;
        }
    }
};

class CurrentAccount : public Account {
public:
    // Override the virtual function to compute and deposit interest for CurrentAccount
    void computeAndDepositInterest() override {
        // Current accounts do not earn interest
        cout << "Interest not applicable for Current Account." << endl;
    }

    // Function to check for the minimum balance and impose penalty if necessary
    void checkMinimumBalance() {
        // Assuming a minimum balance of $1000 and a penalty of $50 for Current Account
        Account::checkMinimumBalance(1000.0, 50.0);
    }
};

class SavingsAccount : public Account {
public:
    // Override the virtual function to compute and deposit interest for SavingsAccount
    void computeAndDepositInterest() override {
        // Assuming a monthly interest rate of 1% for Savings Account
        double interest = balance * 0.01;
        balance += interest;
        cout << "Interest of $" << fixed <<setprecision(2) << interest << " deposited. Updated balance: $" << balance <<endl;
    }

    // Function to check for the minimum balance and impose penalty if necessary
    void checkMinimumBalance() {
        // Assuming a minimum balance of $500 for Savings Account
        Account::checkMinimumBalance(500.0, 0.0);
    }
};

int main() {
    CurrentAccount currentAccount;
    SavingsAccount savingsAccount;

    cout << "Enter details for Current Account:" <<endl;
    currentAccount.initializeAccount();
    currentAccount.displayBalance();
    currentAccount.deposit();
    currentAccount.withdraw();
    currentAccount.checkMinimumBalance();
    currentAccount.displayBalance();

    cout << "\nEnter details for Savings Account:" <<endl;
    savingsAccount.initializeAccount();
    savingsAccount.displayBalance();
    savingsAccount.deposit();
    savingsAccount.computeAndDepositInterest();
    savingsAccount.withdraw();
    savingsAccount.checkMinimumBalance();
    savingsAccount.displayBalance();

    return 0;
}
