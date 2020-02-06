#include <iostream>
#include <iomanip>
 #include "Book.h"
 #include "BookList.h"

BookList::BookList()
{
head = NULL;
}
BookList::~BookList(){
     /*Node *current = head;

    while (current!=head)
    {
        Node* next = current->next;
        delete current;
        current = next;
    }
*/
while(head!=NULL)
    this->deleteAtPosition(head->data->id);

//delete head;
}

  int  BookList::lengthOfList(){
        int length = 0;
        if(this->head == NULL){
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
     bool BookList::addBooks(int id, string title, int year){
        //cout <<" Add books for ::: " << id << endl;
        Book *newBook;

        int length = this->lengthOfList();
        //cout << "length :" << length<<endl;
        /*cout <<"New book " << endl;
        cout <<id << endl;
        cout <<title << endl;
        cout <<year << endl;
        cout << "Arda selam " << endl;*/
        //cout << &newBook << endl;
        newBook = new Book( id, title, year);
        // If the list is empty
        if(head == NULL){
            //cout << "ADD BOOK HEAD NULL"<< endl;
            struct Node* new_node = new Node;
            new_node->data = newBook;
            new_node->next = new_node;
            head = new_node;
            new_node = NULL;
            delete new_node;
            return true;
        }
        //cout <<"Ilk ifin sonrasý " << endl;
        // If the list is not empty
        Node *last = head;
        for(int i = 1 ; i < length ; i++){
            last = last->next;
        }


        // Creating a new node(dynamically)
        struct Node* new_node = new Node;
        new_node->data = newBook;


        // Rearranging the links
        last->next = new_node;
        new_node->next = (head);
        last = NULL;
        delete last;
        return true;

    }
       bool BookList::findBook(int bookId){
           //cout << "FIND BOOK FOR :" << bookId << endl;
            if(head == NULL){
                //cout <<"FIND BOOK but head null" << endl;

                return false;
                }

            else{
                struct Node *temp = head;
                do
                    {
                    if( temp->data->id == bookId )
                        return true;
                    temp = temp->next;

                    }
                while( temp != head );
                return false;
       }
       return false;
       }
       Book* BookList::getBoo(int index){
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
        Book* BookList::getBook( const int bookId ){
        //cout << "Get book for :" << bookId << endl;
        if( head == NULL )
        {
            //cout << " Returning null 1 " << endl;
            return NULL;
        }
        else
        {
            //cout << " Came this far " << endl;
            Node* temp = head;
            do
            {
            //cout << "Eldeki : "<< temp->data->id << endl;
            //cout << "Aranan : "<< bookId << endl;
            if( temp->data->id == bookId )
                //cout << "Return ediyorum" << endl;
                return temp->data;
            temp = temp->next;

            }
            while( temp != head );
            //cout << " Returning null 2 " << endl;
            return NULL;
        }

}
       bool BookList::deleteAtPosition( int bookId){
        struct Node *temp,*previous;
        temp = head;
        previous = NULL;
        bool found = false;
        int length = this->lengthOfList();
        int i = 1;
        if(temp == NULL ){
            cout << "There is no book in the list!" << endl;
            return false;
        }
        else{
            for(i = 1; i <= length ; i++){
                if(temp->data->id == bookId){
                    found = true;
                    break;
                }
                previous = temp;
                temp = temp->next;
            }
        if(!found){
            cout << "Book " << bookId << " does not exist." << endl;
            return false;
        }
        else if(length == 1){
            //delete(temp->data);
            delete(temp);
            //cout << "Making Null wih book id:" << bookId<<endl;
            head = NULL;
        }
        else if (i == 1){
            Node *last = head ;
            for(int i = 1 ; i < length ; i++){
            last = last->next;
            }
            //delete(temp->data);
            head = temp->next;
            last->next = (temp->next);

            delete(temp);
        }
        else if(i == length){
            //delete(temp->data);

            delete(temp);

            previous->next = head;
        }
        else{
            struct Node *after = (temp->next);
            //delete (temp->data);
            delete(temp);
            previous->next = after;
        }
        return true;
        }
    return false;
    }

    void BookList::showBooks(){
        struct Node *temp = head;

        if(temp == NULL){
            cout << "No books in the list !" << endl;
        }
        else{
        while(temp->next != head )
        {
            cout << left << setw(10)<< temp->data->id << setw(20) << temp->data->title << setw(10) << temp->data->year << endl;
            temp = temp->next;

        }
        cout << left << setw(10)<< temp->data->id << setw(20) << temp->data->title << setw(10) << temp->data->year << endl;
    }
    }
/*int main(){
    BookList listOne;
    cout << listOne.lengthOfList()<< endl;
    listOne.addBooks(100,"Eren",1999);
    listOne.showBooks();
    listOne.deleteAtPosition(100);
    listOne.showBooks();
    listOne.addBooks(101,"Cansu",2000);
    listOne.addBooks(102,"Elif",2001);
    listOne.showBooks();
    listOne.deleteAtPosition(102);
    listOne.showBooks();
    cout << listOne.lengthOfList()<< endl;
    listOne.deleteAtPosition(101);
    delete &listOne;

    }

*/


