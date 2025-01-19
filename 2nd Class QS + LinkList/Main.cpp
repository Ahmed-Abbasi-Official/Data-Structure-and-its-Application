#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* nextPtr;

    // Constructor to initialize the node
    Node(int val) {
        data = val;
        nextPtr = NULL;
    }
};

class List{
    Node* head;
    Node* tail;
    public :
    List(){
        head=tail=NULL;
    }

    void push_front(int val){
        Node* newNode=new Node(val);
        if(head == NULL){
            head = tail = newNode;
            return;
        }else{
            newNode->nextPtr = head;
            head = newNode;
        }
    }

    void printLL(){
        Node* temp = head;

        while(temp != NULL){
            cout<<temp->data<<" ";
            temp= temp->nextPtr;
        }
        cout<<endl;
    }
};

int main(){
    List ll;

    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);

    ll.printLL();
    return 0 ;
}