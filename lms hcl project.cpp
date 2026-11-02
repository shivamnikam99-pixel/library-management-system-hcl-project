
#include <iostream>
#include <string>
using namespace std;

struct Book {
    int id;
    string title;
    string author;
    bool issued;
};

Book books[100];
int count = 0;

// Function to add a book
void addBook() {
    if (count >= 100) {
        cout << "Library is full!\n";
        return;
    }

    books[count].id = count + 1;

    cin.ignore();

    cout << "Enter Book Title: ";
    getline(cin, books[count].title);

    cout << "Enter Author Name: ";
    getline(cin, books[count].author);

    books[count].issued = false;

    cout << "\nBook Added Successfully!\n";
    cout << "Book ID: " << books[count].id << endl;

    count++;
}

// Function to display all books
void displayBooks() {
    if (count == 0) {
        cout << "\nNo Books Available.\n";
        return;
    }

    cout << "\n----- BOOK LIST -----\n";

    for (int i = 0; i < count; i++) {
        cout << "\nBook ID: " << books[i].id;
        cout << "\nTitle: " << books[i].title;
        cout << "\nAuthor: " << books[i].author;

        if (books[i].issued == true)
            cout << "\nStatus: Issued\n";
        else
            cout << "\nStatus: Available\n";
    }
}

// Function to search a book
void searchBook() {
    int id;
    cout << "Enter Book ID to Search: ";
    cin >> id;

    for (int i = 0; i < count; i++) {
        if (books[i].id == id) {
            cout << "\nBook Found!";
            cout << "\nTitle: " << books[i].title;
            cout << "\nAuthor: " << books[i].author << endl;
            return;
        }
    }

    cout << "\nBook Not Found!\n";
}

// Function to issue a book
void issueBook() {
    int id;
    cout << "Enter Book ID to Issue: ";
    cin >> id;

    for (int i = 0; i < count; i++) {
        if (books[i].id == id) {
            if (books[i].issued == false) {
                books[i].issued = true;
                cout << "\nBook Issued Successfully!\n";
            } else {
                cout << "\nBook is Already Issued!\n";
            }
            return;
        }
    }

    cout << "\nBook Not Found!\n";
}

// Function to return a book
void returnBook() {
    int id;
    cout << "Enter Book ID to Return: ";
    cin >> id;

    for (int i = 0; i < count; i++) {
        if (books[i].id == id) {
            if (books[i].issued == true) {
                books[i].issued = false;
                cout << "\nBook Returned Successfully!\n";
            } else {
                cout << "\nThis Book Was Not Issued!\n";
            }
            return;
        }
    }

    cout << "\nBook Not Found!\n";
}

// Main Function
int main() {
    int choice;

    do {
        cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Search Book\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "6. Exit\n";

        cout << "\nEnter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addBook();
                break;

            case 2:
                displayBooks();
                break;

            case 3:
                searchBook();
                break;

            case 4:
                issueBook();
                break;

            case 5:
                returnBook();
                break;

            case 6:
                cout << "\nThank You for Using Library System!\n";
                break;

            default:
                cout << "\nInvalid Choice! Try Again.\n";
        }

    } while (choice != 6);

    return 0;
}
