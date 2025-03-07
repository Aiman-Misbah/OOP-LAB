#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct Book
{
    string title;
    string author;
    int year;
};

int main()
{
    int n;
    cout << "Enter the number of books in the library: ";
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << endl;
    Book *books = new Book[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Input Details For Book " << (i + 1) << endl;
        cout << "Enter the title of the book: ";
        getline(cin, books[i].title);
        cout << "Enter the name of the author: ";
        getline(cin, books[i].author);
        cout << "Enter the year of publication: ";
        cin >> books[i].year;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl;
    }
    bool found = false;
    cout << "Books Published after 2010: " << endl;
    for (int i = 0; i < n; i++)
    {
        if (books[i].year > 2010)
        {
            cout << "Book " << (i + 1) << endl;
            cout << "Title: " << books[i].title << endl;
            cout << "Author: " << books[i].author << endl;
            cout << "Year Of Publication: " << books[i].year << endl;
            found = true;
            cout << endl;
        }
    }
    if (!found)
    {
        cout << "No Record Found!";
    }
    delete[] books;
    cout << "Memory Cleared Successfully!" << endl
         << endl;
    return 0;
}