#ifndef __BOOKLIST_H
#define __BOOKLIST_H
#include "Book.h"
using namespace std;
class BookList {
public:
     struct Node {

        Book* data;
        struct Node *next;
        struct Node *prev;

    };
    Node* head;
    BookList();
    ~BookList();
    int lengthOfList();
    bool findBook(int bookId);
    Book* getBoo(int index);
    Book* getBook(int bookId);
    bool addBooks( int id, string title, int year);
    bool deleteAtPosition( int bookId);
    void showBooks();

};
#endif
