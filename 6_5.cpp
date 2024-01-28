#include <iostream>
#include <cstring>
using namespace std;

class Book {
private:
    char* title;
    char* author;
    float price;
    char* publisher;
    int stock;

    static int successfulTransactions; // Static data member to count successful transactions
    static int unsuccessfulTransactions; // Static data member to count unsuccessful transactions

    // Private member function to update book price
    void updatePrice(float newPrice) {
        price = newPrice;
        cout << "Price updated to $" << price << "\n";
    }

public:
    // Default constructor
    Book() : title(nullptr), author(nullptr), price(0.0), publisher(nullptr), stock(0) {}

    // Parameterized constructor
    Book(const char* t, const char* a, float p, const char* pub, int s) {
        title = new char[strlen(t) + 1];
        strcpy(title, t);

        author = new char[strlen(a) + 1];
        strcpy(author, a);

        price = p;

        publisher = new char[strlen(pub) + 1];
        strcpy(publisher, pub);

        stock = s;
    }

    // Destructor to free allocated memory
    ~Book() {
        delete[] title;
        delete[] author;
        delete[] publisher;
    }

    // Member function to search for a book
    bool searchBook(const char* searchTitle, const char* searchAuthor) const {
        return (strcmp(title, searchTitle) == 0 && strcmp(author, searchAuthor) == 0);
    }

    // Member function to display book details
    void displayBookDetails() const {
        cout << "Title: " << title << "\n";
        cout << "Author: " << author << "\n";
        cout << "Price: $" << price << "\n";
        cout << "Publisher: " << publisher << "\n";
        cout << "Stock: " << stock << "\n";
    }

    // Member function to handle book purchase
    void purchaseBook(int requiredCopies) {
        if (requiredCopies <= stock) {
            float totalCost = requiredCopies * price;
            cout << "Total Cost for " << requiredCopies << " copies: $" << totalCost << "\n";
            stock -= requiredCopies;
            successfulTransactions++;
        } else {
            cout << "Required copies not in stock.\n";
            unsuccessfulTransactions++;
        }
    }

    // Member function to update book price (publicly accessible)
    void changePrice(float newPrice) {
        updatePrice(newPrice);
    }

    // Static member function to get successful transactions count
    static int getSuccessfulTransactionsCount() {
        return successfulTransactions;
    }

    // Static member function to get unsuccessful transactions count
    static int getUnsuccessfulTransactionsCount() {
        return unsuccessfulTransactions;
    }

    // Member function to get the address of stock member
    int* getStockAddress() {
        return &stock;
    }
};

// Initialize static data members outside the class
int Book::successfulTransactions = 0;
int Book::unsuccessfulTransactions = 0;

int main() {
    // Create a Book object using dynamic memory allocation
    Book* bookPtr = new Book("The Catcher in the Rye", "J.D. Salinger", 15.99, "Little, Brown and Company", 10);

    // Accessing members using pointers
    cout << "Accessing members using pointers:\n";
    cout << "Title: " << bookPtr->getStockAddress() << "\n";
    cout << "Author: " << bookPtr->getStockAddress() << "\n";
    cout << "Price: $" << *(reinterpret_cast<float*>(bookPtr->getStockAddress() - 1)) << "\n";
    cout << "Publisher: " << bookPtr->getStockAddress() << "\n";
    cout << "Stock: " << *bookPtr->getStockAddress() << "\n";

    // Search for the requested book
    bool bookFound = bookPtr->searchBook("The Catcher in the Rye", "J.D. Salinger");

    // If the book is found, display details and make a purchase
    if (bookFound) {
        cout << "Book Found!\n";
        bookPtr->displayBookDetails();
        bookPtr->purchaseBook(2);
    } else {
        cout << "Book not found in the inventory.\n";
    }

    // Display transaction statistics
    cout << "\nTransaction Statistics:\n";
    cout << "Successful Transactions: " << Book::getSuccessfulTransactionsCount() << "\n";
    cout << "Unsuccessful Transactions: " << Book::getUnsuccessfulTransactionsCount() << "\n";

    // Deallocate dynamic memory
    delete bookPtr;

    return 0;
}
