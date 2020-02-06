#ifndef __STUDENTLIST_H
#define __STUDENTLIST_H
#include "Student.h"
using namespace std;
class StudentList {
public:
    friend istream& operator<<( ostream& out, Student& s );
    friend ostream& operator<<( ostream& out, StudentList& s );
     struct Node {

        Student* data;
        struct Node *next;
        struct Node *prev;

    };
    Node* head;
    StudentList();
    ~StudentList();
    int lengthOfList();
    bool findStudent(int id );
    Student* getStudent(const int studentId);
    Student* getStu(int index);
    bool addStudent( int id, string name);
    bool deleteAtPosition( int checkId);
    void display();


};
#endif

