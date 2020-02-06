#include <iostream>
#include <string.h>
#include <iomanip>
#include "Student.h"
#include "BookList.h"

using namespace std;


Student::~Student(){
    delete &books;
}

Student::Student(int studentId, string studentName){
    id = studentId;
    name = studentName;
    number = 0;
    BookList books;
}

void Student::deleteStudent(int id){
    delete &books;
}
void Student::operator=(const Student &s) {
    this->id = s.id;
    this->name = s.name;
    return;
}

void Student::print(){
    cout<<"Student id : " << this->id << " Student name: " << this->name <<endl;
    if( this->books.lengthOfList() == 0 ){
        cout<<"Student "<< this->id <<" has no books."<<endl;
    }
    else{
        cout<<"Student "<< this->id <<" has checked out the following books:" << endl;
        cout << left << setw(10) << "Book id" <<setw(20)<< "Book name" << setw(10)<< "Year" << endl;
        this->books.showBooks(  );
    }
    }
