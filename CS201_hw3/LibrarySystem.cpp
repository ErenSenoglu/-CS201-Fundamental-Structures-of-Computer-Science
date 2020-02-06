#include <iostream>
#include <iomanip>
#include "LibrarySystem.h"


LibrarySystem::LibrarySystem(){
    BookList notChecked;
    StudentList studentList;
}

LibrarySystem::~LibrarySystem(){
    //delete &notChecked;
    //delete &studentList;
}
void LibrarySystem::addBook(const int bookId, const string name, const int year ){
    bool exist = notChecked.findBook(bookId);
    //cout << exist << endl;
    if(!(exist)){
    bool status = notChecked.addBooks(bookId,name,year);
    if(status){
        cout << "Book " << bookId << " has been added" << endl;
    }
    return;
    }
    else{
        cout << "Book " << bookId << " already exists" << endl;
    }
    return;
}
void LibrarySystem::deleteBook(const int bookId){
    //cout << "Deleting book :" << bookId << endl;
    bool result1 = notChecked.findBook(bookId);
    for(int i = 0 ; i  < studentList.lengthOfList();i++){
    if(studentList.getStu(i)->books.findBook(bookId));
        returnBook(bookId);
        break;
    }
    bool result2 = notChecked.deleteAtPosition(bookId);
    if(result1){
        cout << "Book " << bookId << " has not been checked out" << endl;
        cout << "Book " << bookId << " has been deleted" << endl;
        return;
    }
    else if(result2){
        cout << "Book " << bookId << " has been deleted" << endl;
        return;
    }
}
void LibrarySystem::addStudent(const int studentId, const string name){
    bool exist = studentList.findStudent(studentId);
    if(!(exist)){
    bool result = studentList.addStudent(studentId,name);
    if(result) {
        cout << "Student " << studentId << " has been added" << endl;
    }
    }
    else
        cout << "Student " << studentId << " already exists" << endl;
}
void LibrarySystem::deleteStudent(const int studentId){
    //cout << "Deleting student : " << studentId << endl;
    bool result = studentList.findStudent(studentId);

    if(result){
        Student* stu = studentList.getStudent(studentId);
        for( int i = 0; i < (stu->books.lengthOfList());i){
        //cout << "Return book for i : " << i << endl;
        //cout << "Length :" << stu->books.lengthOfList()<<endl;
        returnBook(stu->books.getBoo(i)->id);
        }
        studentList.deleteAtPosition(studentId);
        cout << "Student " << studentId << " has been deleted" <<endl;
    }
    else
        cout << "Student " << studentId << " does not exist" <<endl;
}
void LibrarySystem::checkoutBook(const int bookId, const int studentId){
    //cout <<"CHeck for " << bookId << endl;
    bool book = notChecked.findBook(bookId);
    //cout << book << endl;
    if(book){

        bool stu = studentList.findStudent(studentId);
        if(!stu){
            cout << "Student " << studentId << " does not exist for checkout" << endl;
            return ;
            }

        //cout <<"SOn if e giriyorum" << endl;
        else{
            Student* toAdd = studentList.getStudent(studentId);
            Book* added = (notChecked.getBook(bookId));
            //cout << "ADD BOOKA GIDIYORUM" << endl;
            toAdd->books.addBooks(added->id,added->title,added->year);
            toAdd->books.getBook(added->id)->checkedBy = studentId;
            toAdd->books.getBook(added->id)->id;
            notChecked.deleteAtPosition(bookId);
            toAdd->books.findBook(bookId);
            //cout << "Checked by artık : "<< added->checkedBy <<" for : " << added->id << endl;
            cout << "Book " << bookId << " has been checked out by student " << studentId << endl;
            return ;
        }

    }
    Student* stude;
        //cout << "Entering for loop " << endl;
        for(int i= 0 ; i < studentList.lengthOfList();i++){
            //cout << i << endl;
            stude = studentList.getStu(i);
            bool result = (stude->books.findBook(bookId));
                if(result){
                    cout << "Book has been already checked out by another student " << endl;
                    return ;
                    }
        }
    cout << "Book " << bookId << " does not exist for checkout" << endl;
    return ;
}
void LibrarySystem::returnBook(const int bookId){
    //cout << "Return book for " << bookId << endl;
    bool check = notChecked.findBook(bookId);
    //cout << check <<endl;
    if(check)
        cout << "Book " << bookId << " has not been checked out" << endl;
    else{
        Student* stu;
        for(int i= 0 ; i < studentList.lengthOfList();i++){
            //cout << "Now we are in for" << endl;
            stu = studentList.getStu(i);

            bool result = (stu->books.findBook(bookId));
                if(result){
                    break;

                }
        }
        //cout << "Stu has :" << stu->books.findBook(bookId) << endl;
        //cout <<" after break"<<endl;
        //cout << "Book ID is : "<<stu->books.getBook(bookId)->id<<endl;
        //if(stu->books.getBook(bookId) == NULL){
        //    cout << "Im null" << endl;
        //}
        Book* toReturn = stu->books.getBook(bookId);
        Book newBook( *toReturn );
        Book* newBookPtr = &newBook;


        //toReturn->checkedBy = 0;

        stu->books.deleteAtPosition(bookId);
          //  cout <<" sas " << endl;
         //       cout <<" sas " << endl;
        //cout << "Not checked : " << (notChecked.head == NULL) << endl;
        //cout << "Not checked : " << notChecked.head->next->data->id << endl;
        //cout << "Not checked : " << notChecked.head->next->next->data->id << endl;
        //cout << "Not checked length : " << notChecked.lengthOfList() << endl;
        //cout << "To return id : " << newBookPtr->id << endl;
        //cout << "To return id : " << newBookPtr->title << endl;
        //cout << "To return id : " << newBookPtr->year << endl;
        notChecked.addBooks(newBookPtr->id,newBookPtr->title,newBookPtr->year);
        //cout << "as" << endl;
        notChecked.getBook(newBookPtr->id)->checkedBy = 0;
        cout <<"Book " << bookId << " has been returned"<< endl;
        return;
}
}
void LibrarySystem::showAllBooks(){
    //cout <<"-----------------" << " 0:"<<endl;
    cout << left << setw(10) << "Book id" << setw(20) << "Book name" << setw(10) << "Year" << setw(20) << "Status " <<endl;
    for(int i= 0 ; i < notChecked.lengthOfList();i++){
        Book* display = notChecked.getBoo(i);
        //cout << "ID is :" << display->id <<endl;
        cout << left << setw(10)<< display->id << setw(20) << display->title << setw(10) << display->year << "Not checked out"<< endl;
        }
     //cout <<"-----------------" << " 1:"<<endl;
     for(int b = 0 ; b < studentList.lengthOfList();b++){
           for(int c =0 ; c < studentList.getStu(b)->books.lengthOfList();c++){
                //cout << "c: " << c<< "ve Lenght :"<< studentList.lengthOfList()<<endl;
            Book* display2 =studentList.getStu(b)->books.getBoo(c);
            cout << left << setw(10)<< display2->id << setw(20) << display2->title << setw(10) << display2->year << "Checked out by "<< display2->checkedBy <<endl;}
     }
     //cout <<"-----------------" << " 2:"<<endl;
}
void LibrarySystem::showBook(const int bookId){
    bool result = notChecked.findBook(bookId);
    if(result){
    Book* display = notChecked.getBook(bookId);
    if(display->checkedBy == 0)
        cout << left << setw(10)<< display->id << setw(20) << display->title << setw(10) << display->year << "Not checked out"<< endl;
    return;
    }
    else{
        //cout << "Im in else" << endl;
        Student* stu;
        //cout << studentList.lengthOfList() << endl;
        bool result = false;
        for(int i= 0 ; i < studentList.lengthOfList()&& !result;i++){
            stu = studentList.getStu(i);
            //cout << stu->id << endl;
            result = (stu->books.findBook(bookId));
            //cout <<"Result : "<< result << endl;
        }
        //cout << "out of loop" << endl;
        Book* displayThis = stu->books.getBook(bookId);
        //cout << displayThis->id << endl;
        cout << left << setw(10)<< displayThis->id << setw(20) << displayThis->title << setw(10) << displayThis->year << "Checked out by "<< displayThis->checkedBy <<endl;
        return;
}
}
void LibrarySystem::showStudent(const int studentId){
    bool exist = studentList.findStudent(studentId);
    if(exist){
    Student* see = (this->studentList.getStudent(studentId));
    see->print();
    }
    else
        cout << "Student " << studentId << " does not exist" << endl;
}
int main() {
LibrarySystem LS;
LS.addBook( 1000, "Machine Learning", 2017 );
LS.addBook( 1200, "Data Mining", 2015 );
LS.addBook( 1300, "Problem S. with C++", 2015 );
LS.addBook( 1400, "C++ How to Program", 2016 );
LS.addBook( 1200, "Data Mining", 2015 );
LS.deleteBook( 1300 );
LS.deleteBook( 2000 );
LS.addBook( 1500, "Pattern Recognition", 2000 );
cout << endl;
LS.addStudent( 21900000, "Furkan Huseyin" );
LS.addStudent( 21900011, "Aynur Dayanik" );
LS.addStudent( 21900011, "Cigdem Gunduz Demir" );
LS.addStudent( 21900020, "Gokhan Akcay" );
LS.addStudent( 21900001, "Cihan Akcay" );
LS.addStudent( 21900005, "Gozde Nur Gunesli" );
LS.deleteStudent( 21900011 );
LS.deleteStudent( 21900050 );
cout << endl;

LS.checkoutBook( 1200, 21900000 );
//cout << "1200 icin check :" << LS.studentList.getStudent(21900000)->books.findBook(1200)<<endl;
LS.checkoutBook( 1400, 21900020 );
LS.checkoutBook( 2050, 21900011 );
LS.checkoutBook( 1000, 21900444 );
LS.checkoutBook( 1500, 21900000 );
//cout << "1500 icin check :" << LS.studentList.getStudent(21900000)->books.getBook(1200)->checkedBy<<endl;
LS.checkoutBook( 1400, 21900001 );
cout << endl;
LS.showStudent( 21900000 );
cout << endl;
LS.showStudent( 21900005 );
cout << endl;
LS.showStudent( 21900011 );
cout << endl;
//cout <<"1000 öncesi" << endl;
LS.showBook( 1000 );
//cout <<"1200 oncesi" << endl;
//cout << LS.studentList.getStu(21900000)->books.findBook(1200) << endl;
//cout <<"-----------------------" << endl;
LS.showBook( 1200 );
//cout << "1200 sonrasi" << endl;
cout << endl;
LS.showAllBooks();
//cout << "All sonrası" << endl;
cout << endl;
LS.returnBook( 1200 );
//cout << " Return 1200 sonrası " << endl;
LS.returnBook( 1000 );
cout << endl;
LS.checkoutBook( 1200, 21900020 );
LS.checkoutBook( 1000, 21900000 );
cout << endl;
//cout << "SHOW ALL BOOKS" << endl;
LS.showAllBooks();
cout << endl;
//cout <<"biz burdayýz "<<endl;
LS.deleteStudent( 21900020 );
cout << endl;
//cout<<"-------------------------------"<<endl;
LS.deleteBook( 1000 );
//cout<<"-------------------------------"<<endl;
cout << endl;
LS.showStudent( 21900000 );
cout << endl;
//cout << "Show 1200: "<<endl;
//LS.showBook(1200);
//cout << "Show All Books" << endl;
LS.showAllBooks();
LS.deleteBook(1400);
LS.deleteBook(1200);
LS.deleteBook(1500);
LS.deleteStudent(21900000);
LS.deleteStudent(21900020);
return 0;
}
