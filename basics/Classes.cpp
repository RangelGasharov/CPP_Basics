#include <iostream>
#include <cmath>

using namespace std;

class Book {
public:
    string title;
    string author;
    int pages;
};

int main() {
    Book book1;
    book1.title = "Lord of the Rings";
    book1.author = "Tolkein";
    book1.pages = 720;

    Book book2;
    book2.title = "Harry Potter";
    book2.author = "JK Rowling";
    book2.pages = 650;

    cout << book1.title << endl;
    cout << book2.title << endl;
    return 0;
}