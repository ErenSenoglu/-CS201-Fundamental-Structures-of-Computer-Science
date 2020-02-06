#ifndef __BOOK_H
#define __BOOK_H

#include <string>
using namespace std;

class Book{
public:
   Book( int id = 0,  string title = "",  int year = 0 );
   Book( const Book& bookToCopy );
   ~Book();
   Book& operator=( const Book& right );
   void changeBy(int id );
public:
   string title;			// Title of the book
   int year;			// Price of the book
   int id;
   int checkedBy;			// Number of the editions of the book
        // A list of the years of the book's editions
							// Note that each book can have zero or more editions

};

#endif

