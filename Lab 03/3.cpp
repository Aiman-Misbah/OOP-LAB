#include <iostream>
using namespace std;
#define maxBooks 100

class Library
{
private:
    string bookList[maxBooks];
    string borrowedBooks[maxBooks];
    string availableBooks[maxBooks];

public:
    void addBook(string book)
    {
        for (int i = 0; i < maxBooks; i++)
        {
            if (bookList[i] == book)
            {
                cout << "Error: The book '" << book << "' is already in the library!" << endl;
                return;
            }
        }
        for (int i = 0; i < maxBooks; i++)
        {
            if (bookList[i] == "")
            {
                bookList[i] = book;
                for (int j = 0; j < maxBooks; j++)
                {
                    if (availableBooks[j] == "")
                    {
                        availableBooks[j] = book;
                        return;
                    }
                }
            }
        }
        cout << "Error, Maximum Book Capacity Achieved For The Library!" << endl;
    }

    void displayBookList()
    {
        bool hasBooks = false;
        cout << "---------Library Books----------" << endl;
        for (int i = 0, count = 1; i < maxBooks; i++)
        {
            if (bookList[i] != "")
            {
                cout << count++ << ". " << bookList[i] << endl;
                hasBooks = true;
            }
        }
        if (!hasBooks)
            cout << "No books available in the library!" << endl;
    }

    void lendBook(string book)
    {
        for (int i = 0; i < maxBooks; i++)
        {
            if (availableBooks[i] == book)
            {
                for (int j = 0; j < maxBooks; j++)
                {
                    if (borrowedBooks[j] == "")
                    {
                        borrowedBooks[j] = book;
                        cout << book << " Borrowed From The Library! " << endl;
                        for (int k = i; k < maxBooks - 1; k++)
                            availableBooks[k] = availableBooks[k + 1];
                        availableBooks[maxBooks - 1] = "";
                        return;
                    }
                }
            }
        }
        cout << "Error, " << book << " is not currently available for lending! " << endl;
    }

    void displayLentBooks()
    {
        bool hasBorrowed = false;
        cout << "---------Borrowed Books----------" << endl;
        for (int i = 0; i < maxBooks; i++)
        {
            if (borrowedBooks[i] != "")
            {
                cout << (i + 1) << ". " << borrowedBooks[i] << endl;
                hasBorrowed = true;
            }
        }
        if (!hasBorrowed)
            cout << "No books have been borrowed yet!" << endl;
    }

    void returnBook(string book)
    {
        for (int i = 0; i < maxBooks; i++)
        {
            if (borrowedBooks[i] == book)
            {
                borrowedBooks[i] = "";
                for (int j = 0; j < maxBooks; j++)
                {
                    if (availableBooks[j] == "")
                    {
                        availableBooks[j] = book;
                        cout << book << " Returned To The Library! " << endl;
                        return;
                    }
                }
            }
        }
        cout << "Error: This book was not borrowed!" << endl;
    }

    void displayAvailableBooks()
    {
        bool hasBooks = false;
        cout << "---------Available Books----------" << endl;
        for (int i = 0, count = 1; i < maxBooks; i++)
        {
            if (availableBooks[i] != "")
            {
                cout << count++ << ". " << availableBooks[i] << endl;
                hasBooks = true;
            }
        }
        if (!hasBooks)
            cout << "No books available in the library!" << endl;
    }
};

int main()
{
    Library library;
    library.addBook("The Great Gatsby");
    library.addBook("To Kill a Mockingbird");
    library.addBook("1984");
    library.addBook("Pride and Prejudice");
    library.addBook("Moby-Dick");
    library.addBook("War and Peace");
    library.addBook("The Catcher in the Rye");
    library.addBook("The Hobbit");
    library.addBook("The Lord of the Rings");
    library.addBook("Harry Potter and the Sorcerer’s Stone");
    library.addBook("The Da Vinci Code");
    library.addBook("The Alchemist");
    library.addBook("Brave New World");
    library.addBook("The Road");
    library.addBook("The Book Thief");
    library.addBook("Crime and Punishment");
    library.addBook("Les Misérables");
    library.addBook("Anna Karenina");
    library.addBook("The Picture of Dorian Gray");
    library.addBook("Don Quixote");

    library.displayBookList();
    cout << endl;

    library.lendBook("1984");
    library.lendBook("The Hobbit");
    library.lendBook("The Great Gatsby");
    library.lendBook("The Alchemist");
    cout << endl;

    library.displayLentBooks();
    cout << endl;

    library.returnBook("1984");
    library.returnBook("The Hobbit");
    cout << endl;

    library.displayAvailableBooks();
    return 0;
}

