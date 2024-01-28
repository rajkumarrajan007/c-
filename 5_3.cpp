#include <iostream>
#include <string>
#include <vector>
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
        cout << "Amount deposited successfully. New balance: " << balance << endl;
    }

    // Member function to withdraw an amount after checking the balance
    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Amount withdrawn successfully. New balance: " << balance <<endl;
        } else {
            cout << "Insufficient balance. Withdrawal failed." << endl;
        }
    }

    // Member function to display name and balance
    void displayInfo() const {
        cout << "Account Holder: " << depositorName << endl;
        cout << "Account Number: " << accountNumber <<endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    const int numCustomers = 10;
    vector<BankAccount> customerAccounts(numCustomers);

    // Initialize accounts for 10 customers
    for (int i = 0; i < numCustomers; ++i) {
        customerAccounts[i].initializeAccount("Customer " + to_string(i + 1), 1000 + i, "Savings", 1000.0);
    }

    // Display account information for all customers
    for (const auto& account : customerAccounts) {
        account.displayInfo();
        cout << endl;
    }

    // Deposit and withdraw for a specific customer (e.g., customer 3)
    int customerIndex = 2;  // Index 2 corresponds to customer 3 (0-based index)
    customerAccounts[customerIndex].deposit(500.0);
    customerAccounts[customerIndex].withdraw(200.0);

    // Display updated account information for the specific customer
    cout << "Updated Account Information for Customer 3:\n";
    customerAccounts[customerIndex].displayInfo();

    return 0;
}
