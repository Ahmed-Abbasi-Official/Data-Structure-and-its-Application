#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data=val;
        next=NULL;
    }
};

class CircularList{
    Node* head;
    Node* tail;
    public:

    CircularList(){
        head=tail=NULL;
    }

    // * PUSH FRONT

    void push_front(int val){
        Node* newNode=new Node(val);
        if(head==NULL){
            head=tail=newNode;
            tail->next=newNode;
        }
        else{
            newNode->next=head;
            head=newNode;
            tail->next=head;
        }
    }

    // * PRINT LIST

    void printLL(){
        Node* temp = head;
        cout<<temp->data<<"->";
        temp=temp->next;
        while(temp != tail->next){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
    }



};

int main(){

    CircularList cll;

    cll.push_front(1);
    cll.push_front(2);
    cll.push_front(3);

    cll.printLL();

}