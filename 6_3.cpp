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

    // Member function to search for a book and display details
    void searchBook(const char* searchTitle, const char* searchAuthor) const {
        if (strcmp(title, searchTitle) == 0 && strcmp(author, searchAuthor) == 0) {
            cout << "Book Found!\n";
            displayBookDetails();
        } else {
            cout << "Book not found.\n";
        }
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
        } else {
            cout << "Required copies not in stock.\n";
        }
    }
};

int main() {
    // Create a Book object
    Book book1("The Catcher in the Rye", "J.D. Salinger", 15.99, "Little, Brown and Company", 10);

    // Search for a book
    book1.searchBook("The Catcher in the Rye", "J.D. Salinger");

    // Purchase some copies
    book1.purchaseBook(3);

    // Display updated book details
    cout << "Updated Book Details:\n";
    book1.displayBookDetails();

    return 0;
}
