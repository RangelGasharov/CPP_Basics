#include <iostream>
#include <cmath>

using namespace std;

class Book {
public:
    string title;
    string author;
    int pages;

    Book() {
        title = "no title";
        author = "no author";
        pages = 0;
    }

    Book(string aTitle, string aAuthor, int aPages) {
        title = aTitle;
        author = aAuthor;
        pages = aPages;
    }

    bool isOverThousandPages() {
        if (pages >= 1000) {
            return true;
        }
        return false;
    }
};

int main() {
    Book book1("Lord of the Rings", "Tolkein", 720);
    Book book2("Harry Potter", "JK Rowling", 650);
    Book book3;
    Book book4("The Count of Monte Cristo", "Alexandre Dumas", 1200);

    cout << book1.title << endl;
    cout << book2.title << endl;
    cout << book3.title << endl;
    cout << book2.isOverThousandPages() << endl;
    cout << book4.isOverThousandPages() << endl;
    return 0;
}