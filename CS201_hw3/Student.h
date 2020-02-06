#ifndef __STUDENT_H
#define __STUDENT_H

#include <iostream>
#include <string>
#include "BookList.h"
using namespace std;

class Student {
   public:

        BookList books;
        int id;
        string name;
        int number;
        Student(int id = 0, string name="") ;
        ~Student();


        void print();

        void operator=(const Student &s);

        void deleteStudent(int id);
            //Check if it exists, display a warning message
            // Else return the books and delete student.

};
#endif

