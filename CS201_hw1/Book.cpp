#include <iostream>
#include <sstream>
#include "Book.h"
using namespace std;

Book::Book( const string bookTitle , const double bookPrice ){
    title = bookTitle;
    price = bookPrice;
    editionYears = NULL;
    editionNo = 0;
}
Book::Book( const Book &bookToCopy){
    title = bookToCopy.title;
    price = bookToCopy.price;
    editionNo = bookToCopy.editionNo;
    editionYears = new int [bookToCopy.editionNo];
    for(int i = 0 ; i < bookToCopy.editionNo ; i++){
        addEdition(bookToCopy.editionYears[i]);
    }
}
void Book::addEdition(const int newEditionYear){

    int* temp = new int[editionNo];

    for(int i = 0; i < editionNo; i++){
            temp[i] = editionYears[i];
    }

    delete [] editionYears;
    editionYears = new int[editionNo+1];

    for(int i = 0; i < editionNo; i++){
            editionYears[i] = temp[i];
    }
    delete [] temp;

    editionYears[editionNo] = newEditionYear;
    editionNo++;

}
Book::~Book(){
    if(editionNo > 0)
        delete [] editionYears;
}
ostream &operator<<( ostream &output, const Book &b){
    output << b.title << ", ";
    output << b.price << " TL ";
     if(b.editionNo == 0 )
            output << "(none)";
    for(int i = 0 ; i < b.editionNo ; i++){
        if(i == 0)
           output << "(";

        if((b.editionNo)-1 == i){
            output << b.editionYears[i] << ")";
            }
        if((b.editionNo)-1 != i)
            output << b.editionYears[i] << ", ";

    }
    return output;
}

istream &operator>>(istream &input, Book &b){

    string line = "";
    //string::const_iterator iterator1 = line.begin();
    if(b.editionNo > 0)
        delete [] b.editionYears;

    b.editionYears = new int[5];
    b.editionNo = 0;

    cout << "Enter all edition years for the " << b.title << " : ";
    getline(cin,line);
    bool flag = true;
    string year = "";
    int yearInt = 0;

    for(int i = 0 ; flag ; i++){
        if(isspace(line [i]) || line[i] == '\0' ){
                if(!(year.empty())){
                istringstream(year) >> yearInt;
                //yearInt = std::stoi(year);
                //cout << "Adding edition" << endl;
                b.addEdition(yearInt);
                year ="";
        }
        if(line[i] == '\0')
            flag = false;
        }
        else{
            year += line[i];
            //cout << "Year String is : " << year << endl;
        }
    }
   /* while( iterator1 != line.end()){
        if(isspace(*iterator1)){
            istringstream(year) >> yearInt;
            cout << yearInt << endl;
            if(yearInt != 0){
                cout << "Adding to edition" << endl;
                b.addEdition(yearInt);
            }

        year = "";
        yearInt = 0;
        }
        else{
            cout << "Appending year" << endl;
            year += *iterator1;
            cout << "string year: " << year << endl;
            }
        iterator1++;
    }
    cout << "out of loop" << endl;
    istringstream(year) >> yearInt;
    if(yearInt != 0)
        b.addEdition(yearInt);
        */
    return input;
}
Book& Book::operator=(const Book &right){
    if( right.title != this->title){
        if(right.price != this->price){
            this->title = right.title;
            this->price = right.price ;
            this->editionNo = right.editionNo;
            delete [] this->editionYears;
            editionYears = new int[right.editionNo];
            for(int i = 0 ; i < right.editionNo ; i++){
                this->editionYears[i] = right.editionYears[i];
            }
        }
    }
    return *this;
}
