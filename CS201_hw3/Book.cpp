#include <iostream>
#include <sstream>
#include "Book.h"
using namespace std;

Book::Book( int bookID, string bookTitle , int bookYear ){
    //cout <<"Creating a new book id : " << id << endl;
    id = bookID;
    title = bookTitle;
    //cout <<"Creating new book id : " << id <<" title :" << title<<endl;
    year = bookYear;
    checkedBy = 0;
    //cout <<"Creating a new book id : " << id << endl;
}
Book::Book( const Book &bookToCopy){
    title = bookToCopy.title;
    year = bookToCopy.year;
    id = bookToCopy.id;

}
Book::~Book(){
}
void Book::changeBy(int id){
    checkedBy = id;
}


