# Library Management System (LMS)

A simple console-based Library Management System written in C++ that allows you to manage books using file handling. Books are stored in a human-readable CSV format.

## Features

- **Add Book:** Add new books with unique IDs.
- **Books List:** View all available books.
- **Search Book:** Search for books by name or author.
- **Remove Book:** Delete books by ID.
- **Input Validation:** Ensures only valid integer input for menu and book IDs.

## File Structure

- `LMS.cpp` — Main source code file.
- `books.txt` — Stores book records in CSV format:  
  ```
  id,bookName,authorName
  ```

## How to Compile and Run

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

On running, you will see a menu:
```
<== Library Management System ==>
1. Add Book
2. Books List
3. Search Book
4. Remove Book
0. Exit
```
Enter the number corresponding to your desired action and follow the prompts.

## Example `books.txt` Format

```
1,Harry Potter,J.K. Rowling
2,The Hobbit,J.R.R. Tolkien
```

## License

This project is for educational purposes.