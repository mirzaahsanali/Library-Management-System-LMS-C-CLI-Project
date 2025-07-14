# Library Management System (LMS)

A simple, interactive console-based Library Management System written in C++. This project demonstrates basic file handling by allowing users to manage a collection of books, with all data stored in a readable CSV format.

## Features

- **Add Book:** Add new books with unique IDs and author names.
- **Books List:** Display all available books in a formatted table.
- **Search Book:** Search for books by name or author.
- **Remove Book:** Delete books by their ID.
- **Input Validation:** Ensures only valid integer input for menu and book IDs.
- **Persistent Storage:** All book data is saved in `books.txt` for future use.

## File Structure

- `LMS.cpp` — Main source code file containing all logic.
- `books.txt` — Stores book records in CSV format:
  ```
  id,bookName,authorName
  ```

## Getting Started

### Prerequisites

- C++ compiler (e.g., [g++](https://gcc.gnu.org/))
- Windows command prompt or any terminal

### Compile and Run

1. Open a terminal in the project directory.
2. Compile the code:
    ```sh
    g++ LMS.cpp -o LMS.exe
    ```
3. Run the executable:
    ```sh
    ./LMS.exe
    ```

## Usage

When you run the program, you'll see a menu:
```
<== Library Management System ==>
1. Add Book
2. Books List
3. Search Book
4. Remove Book
0. Exit
```
Enter the number for your desired action and follow the prompts.

### Example `books.txt` Format

```
1,Harry Potter,J.K. Rowling
2,The Hobbit,J.R.R. Tolkien
```

## Contributing

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change or improve.

## License

This project is for educational purposes and is provided without warranty.