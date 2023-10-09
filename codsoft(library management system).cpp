#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

// Define structures for Book and Borrower
struct Book {
    string title;
    string author;
    string ISBN;
    bool available;

    Book(string t, string a, string i) : title(t), author(a), ISBN(i), available(true) {}
};

struct Borrower {
    string name;
    int borrowerID;
    vector<Book*> borrowedBooks;

    Borrower(string n, int id) : name(n), borrowerID(id) {}
};

// Function to search for books by title, author, or ISBN
void SearchBooks(const vector<Book>& books, const string& searchTerm) {
    cout << "Search results:" << endl;
    for (const Book& book : books) {
        if (book.title.find(searchTerm) != string::npos ||
            book.author.find(searchTerm) != string::npos ||
            book.ISBN.find(searchTerm) != string::npos) {
            cout << "Title: " << book.title << endl;
            cout << "Author: " << book.author << endl;
            cout << "ISBN: " << book.ISBN << endl;
            cout << "Availability: " << (book.available ? "Available" : "Checked Out") << endl;
            cout << endl;
        }
    }
}

// Function to check out a book to a borrower
void CheckOutBook(Book& book, Borrower& borrower) {
    if (book.available) {
        book.available = false;
        borrower.borrowedBooks.push_back(&book);
        cout << "Book checked out successfully." << endl;
    } else {
        cout << "Book is already checked out." << endl;
    }
}

// Function to record book return
void ReturnBook(Book& book, Borrower& borrower) {
    if (!book.available) {
        book.available = true;
        // Calculate fine for overdue books (you can define your rules)
        // Update borrower's borrowedBooks vector
        cout << "Book returned successfully." << endl;
    } else {
        cout << "Book is already available." << endl;
    }
}

int main() {
    vector<Book> books;
    vector<Borrower> borrowers;

    // Populate books and borrowers (you can add more here)

    while (true) {
        cout << "\nLibrary Management System\n";
        cout << "1. Search Books\n";
        cout << "2. Check Out Book\n";
        cout << "3. Return Book\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                {
                    string searchTerm;
                    cout << "Enter search term (title, author, or ISBN): ";
                    cin >> searchTerm;
                    SearchBooks(books, searchTerm);
                    break;
                }
            case 2:
                {
                    int borrowerID;
                    cout << "Enter borrower ID: ";
                    cin >> borrowerID;
                    // Implement book checkout functionality
                    break;
                }
            case 3:
                {
                    int borrowerID;
                    cout << "Enter borrower ID: ";
                    cin >> borrowerID;
                    // Implement book return functionality
                    break;
                }
            case 4:
                cout << "Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please select a valid option." << endl;
        }
    }

    return 0;
}
