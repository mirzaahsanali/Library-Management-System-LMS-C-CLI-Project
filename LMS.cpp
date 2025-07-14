#include <iostream>
#include <iomanip> //for setw (formatting of displaying list of books)
#include <fstream> 
#include <limits>

using namespace std;

// Structures for storing book and student information
struct Book {
    int id;
    char bookName[50];
    char authorName[50];
} b;

struct Student {
    char Name[50];
    char Class[50];
    char bookName[50];
} s;

fstream fp;

// Function prototypes
void exit();
void addBook();
void booksList();
void searchBook();
void removeBook();

// Function to validate integer input
int getValidIntegerInput() {
    int input;
    while (!(cin >> input)) { //takes input again and again untill entered value is not int;
        cout << "Invalid input. Please enter a valid integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n'); //discards characters in the input buffer until a newline ('\n')
    }
    return input;
}

int main() {
    int choice;

    while (true) {
        system("cls");  // Clear the console screen

        // Display menu options
        cout << "<== Library Management System ==>\n";
        cout << "1. Add Book\n";
        cout << "2. Books List\n";
        cout << "3. Search Book\n";
        cout << "4. Remove Book\n";
        cout << "0. Exit\n\n";
        cout << "Enter your choice: ";
        choice = getValidIntegerInput();

        // Switch statement to select menu option
        switch (choice) {
            case 0: exit(); break; 
            case 1: addBook(); break;
            case 2: booksList(); break;
            case 3: searchBook(); break;
            case 4: removeBook(); break;
            default: cout << "Invalid Choice...\n\n";
        }

        cout << "Press Any Key To Continue...";
        cin.ignore();
        cin.get();
    }

    return 0;
}

// ========================== ADD BOOK FUNCTION ==========================
void addBook() {
    ifstream fin("books.txt");
    int enteredId;
    bool idExists = false;

    cout << "Enter book id: ";
    enteredId = getValidIntegerInput();

    string line;
    while (getline(fin, line)) {
        int id;
        sscanf(line.c_str(), "%d,", &id);
        if (id == enteredId) {
            idExists = true;
            cout << "Book with this ID already exists. Please enter a different ID: ";
            enteredId = getValidIntegerInput();
            fin.clear();
            fin.seekg(0, ios::beg);
        }
    }
    fin.close();

    ofstream fout("books.txt", ios::app);

    char bookName[50], authorName[50];
    cout << "Enter book name: ";
    cin.ignore();
    cin.getline(bookName, sizeof(bookName));

    cout << "Enter author name: ";
    cin.getline(authorName, sizeof(authorName));

    fout << enteredId << "," << bookName << "," << authorName << "\n";
    cout << "Book Added Successfully" << endl;
    fout.close();
}

// ========================== VIEW BOOK LIST FUNCTION ==========================
void booksList() {
    system("cls");
    cout << "<== Available Books ==>\n\n";
    cout << setw(10) << left << "ID" << setw(30) << left << "Book Name" << setw(30) << left << "Author" << "\n\n";
    ifstream fin("books.txt");
    string line;
    while (getline(fin, line)) {
        int id;
        char bookName[50], authorName[50];
        sscanf(line.c_str(), "%d,%49[^,],%49[^\n]", &id, bookName, authorName);
        cout << setw(10) << left << id << setw(30) << left << bookName << setw(30) << left << authorName << endl;
    }
    fin.close();
}

// ========================== SEARCH BOOK FUNCTION ==========================
void searchBook() {
    system("cls");
    cout << "<== Search Books ==>\n\n";
    string search;
    bool bookFound = false;
    cout << "Enter book name or author name: ";
    cin.ignore();
    getline(cin, search);
    cout << setw(10) << left << "ID" << setw(30) << left << "Book Name" << setw(20) << left << "Author" << "\n\n";
    ifstream fin("books.txt");
    string line;
    while (getline(fin, line)) {
        int id;
        char bookName[50], authorName[50];
        sscanf(line.c_str(), "%d,%49[^,],%49[^\n]", &id, bookName, authorName);
        if (search == bookName || search == authorName) {
            cout << setw(10) << left << id << setw(30) << left << bookName << setw(20) << left << authorName << endl;
            bookFound = true;
        }
    }
    if (!bookFound) {
        cout << "No book with the given Name or Author found!" << endl;
    }
    fin.close();
}

// ========================== REMOVE BOOK FUNCTION ==========================
void removeBook() {
    int id;
    bool found = false;
    system("cls");
    cout << "<== Remove Book ==>\n\n";
    cout << "Enter Book ID to remove: ";
    id = getValidIntegerInput();

    ifstream fin("books.txt");
    ofstream fout("temp.txt");
    string line;
    while (getline(fin, line)) {
        int bookId;
        sscanf(line.c_str(), "%d,", &bookId);
        if (id == bookId) {
            found = true;
        } else {
            fout << line << "\n";
        }
    }
    fin.close();
    fout.close();

    if (found) {
        cout << "Book deleted successfully." << endl;
    } else {
        cout << "Book not found!" << endl;
    }

    remove("books.txt");
    rename("temp.txt", "books.txt");
}

void exit() {
    cout << "Thank you for using our LMS. Goodbye." << endl;
    exit(0);
}