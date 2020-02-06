#include <iostream>
#include "StudentList.h"
#include "Student.h"
using namespace std;

 StudentList::StudentList(){
     head = NULL;
 }
 StudentList::~StudentList(){
    /*Node *current = head;

    while (current!=head)
    {
        Node* next = current->next;
        delete current;
        current = next;
    }*/
while(head!=NULL)
    this->deleteAtPosition(head->data->id);
//delete head;
 }

    bool StudentList::addStudent( int id, string name){
        if(id <= 0)
            return false;
        Student *newStudent = new Student(id, name);
        // If the list is empty
        if(head == NULL){
            struct Node* new_node = new Node;
            new_node->data = newStudent;
            new_node->next = new_node->prev = new_node;
            head = new_node;
            new_node = NULL;
            delete new_node;
            return true;
        }
        else{
        // If the list is not empty

        Node *last = (head)->prev;

        // Creating a new node(dynamically)
        struct Node* new_node = new Node;
        new_node->data = newStudent;


        // Rearranging the links
        last->next = new_node;
        new_node->prev = last;
        (head)->prev = new_node;
        new_node->next = (head);
        last = NULL;
        delete last;
        return true;
        }
    return false;
    }
    bool StudentList::findStudent(int studentId){
        if(head == NULL)
            return false;
        else{
            struct Node *temp = head;
                do
                    {
                    if( temp->data->id == studentId )
                        return true;
                    temp = temp->next;

                    }
                while( temp != head );
                return false;
    }
    }
     int StudentList::lengthOfList(){
        int length = 0;
        if(head == NULL){
            return length;
        }
        struct Node* temp = head;
        while(temp->next != head){
            temp = temp->next;
            length++;
        }
        length++;


        return length;


    }
     bool StudentList::deleteAtPosition( int checkId){
        struct Node *temp,*previous;
        temp = head;
        previous = NULL;
        bool found = false;
        int length = this->lengthOfList();
        int i = 1;
        if(temp == NULL ){
            cout << "There is no student in the list!" << endl;
            return false;
        }
        else{
            for(i = 1; i <= length ; i++){
                if(temp->data->id == checkId){
                    found = true;
                    break;
                }
                previous = temp;
                temp = temp->next;
            }
        if(!found){
            cout << "Student " << checkId << " does not exist." << endl;
            return false;
        }
        else if(length == 1){
            //delete(temp->data);
            delete(temp);
            head = NULL;
        }
        else if (i == 1){
            Node *last = temp->prev ;
            //delete(temp->data);
            head = temp->next;
            (temp->next)->prev = last;
            last->next = (temp->next);
            delete(temp);
        }
        else if(i == length){
            //delete(temp->data);
            delete(temp);
            previous->next = head;
            (head)->prev = previous;
        }
        else{
            struct Node *after = (temp->next);
            //delete (temp->data);
            delete(temp);
            previous->next = after;
            after->prev = previous;
        }
        return true;
        }
    return false;
    }
    Student* StudentList::getStu(int index){
        struct Node *temp = head;
            if(temp == NULL){
                return NULL;
            }
            else{
                for(int i = 0; i < index ; i++){
                    temp = temp->next;
                }
                return temp->data;
            }
    }
    void StudentList::display(){
        struct Node *temp = head;
        if(temp == NULL){
            cout << "No students in the list !" << endl;
        }
        else{
        while(temp->next != head )
        {
            cout << "ID is : " << temp->data->id << " and name is : " << temp->data->name << endl;
            temp = temp->next;

        }
        cout << "ID is : " << temp->data->id << " and name is : " << temp->data->name << endl;
    }
    }
    Student* StudentList::getStudent( const int studentId )
{
    if( head == NULL )
    {

        return NULL;
    }
    else
    {
        Node* cur = head;

        do
        {

            if( cur->data->id == studentId )
                return cur->data;
            cur = cur->next;

        }
        while( cur != head );
        return NULL;
    }

}
ostream& operator<<( ostream& out, Student* s )
{
    out<<"Student id : " << s->id << " Student name: " << s->name <<endl;
    if( s->books.lengthOfList() == 0 ){
        out<<"Student "<< s->id <<" has no books.";
    }
    else{
        out<<"Student "<< s->id <<" has checked out the following books:";
        s->books.showBooks(  );
    }

    return out;
}
ostream& operator<<( ostream& out, const StudentList& s )
{
if( s.head != NULL )
    {
        StudentList::Node* cur = s.head;
        do
        {
            out<< cur->data;
            cur = cur -> next;

        }
        while( cur != s.head );

    }


    return out;
}

   /* int main(){
    StudentList listOne;
    cout << listOne.lengthOfList()<< endl;
    listOne.addStudent(21702079,"Eren");
    listOne.display();
    listOne.deleteAtPosition(21702079);
    listOne.display();
    listOne.addStudent(21832944,"Cansu");
    listOne.addStudent(21932944,"Elif");
    listOne.display();
    cout << listOne.lengthOfList()<< endl;
    listOne.deleteAtPosition(21832944);
    listOne.display();
    listOne.deleteAtPosition(21932944);
    listOne.display();
    delete &listOne;
    }


*/
