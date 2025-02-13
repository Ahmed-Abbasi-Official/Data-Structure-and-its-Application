#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int val){
        data=val;
        next=prev=NULL;
    }
};

class DoublyList{
    Node* head;
    Node* tail;
    public:
    DoublyList(){
        head=tail=NULL;
    }

    // * PUSH FRONT

    void push_front(int val){
        Node* newNode = new Node(val);

    if(head==NULL){
        head=tail=newNode;
        return;
    }else{
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
    }
    }

      // * DISPLAY DOUBLE LISTT

      void print_dll(){
        Node* temp = head;
        while(temp !=NULL){
            cout<<" "<<temp->data<<"<==>";
            temp = temp->next;
        }
        cout<<"NULL\n";
    }

};

  
 
int main (){

    DoublyList dll;

    dll.push_front(1);
    dll.push_front(2);
    dll.push_front(3);

    dll.print_dll();
}