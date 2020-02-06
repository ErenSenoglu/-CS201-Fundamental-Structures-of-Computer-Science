#include <iostream>
#include <string.h>
#include <stdexcept>
#include "BookStore.h"
#include "Book.h"
using namespace std;

BookStore::BookStore(){
    books = NULL;
    bookNo = 0;
}
BookStore::~BookStore(){
    if(books != NULL)
        delete [] books;
}

BookStore::BookStore(const BookStore& bsToCopy){
    books = new Book[bsToCopy.bookNo];
    bookNo = 0;
    for(int i = 0; i < bsToCopy.bookNo ; i++){
        addBook(bsToCopy.books[i].title,bsToCopy.books[i].price);

    for(int j = 0; j < bsToCopy.books[i].editionNo ; j++ ){
            (books[i]).addEdition(bsToCopy.books[i].editionYears[j]);
        }
        }
    bookNo = bsToCopy.bookNo;
}

 Book& BookStore::operator[](const string title){
        for(int i = 0; i < bookNo ;i++){
            if(title.compare(this->books[i].title) == 0)
                return this->books[i];
        }
        string error ="Cannot access a non-existing book (" + title +")";
        throw invalid_argument(error);
    }

BookStore& BookStore::operator=( const BookStore& right){
    if( this == &right)
        return *this;
    if(bookNo > 0)
        delete [] books;
    bookNo = right.bookNo;
    for(int i = 0; i < right.bookNo ; i++){
        addBook(right.books[i].title,right.books[i].price);
        for(int j = 0; j < right.books[i].editionNo ; j++ ){
            (books[i]).addEdition(right.books[i].editionYears[j]);
        }
    }

    return *this;
}

void BookStore::addBook(const string bookTitle, const double bookPrice){
    for(int i = 0 ; i < bookNo; i++){
        if(bookTitle.compare(books[i].title) == 0){
            string error ="Cannot add an already existing book (" + bookTitle + ")";
            throw invalid_argument(error);
            }
    }
    Book* toAdd = new Book(bookTitle,bookPrice);
    Book* temp = new Book[bookNo];

    for(int i = 0; i < bookNo; i++){
            temp[i] = books[i];
        }
        if(books != NULL){
            delete [] books;
        }
    books = new Book[bookNo+1];

    for(int i = 0; i < bookNo; i++){
            books[i] = temp[i];
        }


    books[bookNo] = *toAdd;
    delete toAdd;
    bookNo++;
    delete [] temp;
}

void  BookStore::removeBook(const string bookTitle){
        bool flag = true;
        int pos = -1;
        for(int i = 0 ; i < bookNo ; i++){
            if(books[i].title.compare(bookTitle) == 0){
                flag = false;
                pos = i;
        }
        }
        if(flag){
            string error ="Cannot remove a non-existing book (" + bookTitle + ")";
            throw invalid_argument(error);
        }
        // If that book exist in the book store. It will be removed.
        else{
        bool passed = false;
        Book* temp = new Book[bookNo-1];

        for(int i = 0; i < bookNo; i++){
            if( i > pos )
                passed = true;
            if(passed)
                temp[i-1] = books[i];
            else if(!passed)
                temp[i] = books[i];
        }
        if(books != NULL)
            delete [] books;
        books = new Book[bookNo-1];

        for(int i = 0; i < bookNo-1; i++){
                books[i] = temp[i];
        }
        if(temp != NULL)
            delete [] temp;
        bookNo--;
            }
       }
ostream& operator<<( ostream& out, const BookStore& b ){
    for(int i = 0 ; i < b.bookNo ; i++){
        cout << b.books[i] << endl;
    }
    return out;
}



