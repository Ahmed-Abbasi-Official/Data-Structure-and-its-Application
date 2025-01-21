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

    // POP FRONT

    void pop_front(){
        Node* temp = head ;
        head=head->nextPtr;
        temp->nextPtr=NULL;

        delete temp ;
    }

    // PUSH FRONT

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

    // PRINT ALL
    
    void printLL(){
        Node* temp = head;
        

        while(temp != NULL){
            cout<<" "<<temp->data<<" ";
            temp= temp->nextPtr;
        }
        cout<<endl;
    }

    // PUSH BACK

    void push_back(int val){
        Node* newNode=new Node(val);
        if(head==NULL){
            head = tail = newNode;
            // newNode->nextPtr=head;
            return;
        }else{
            tail->nextPtr=newNode;
            tail=newNode;
        }
    }

      // POP BACK

    void pop_back(){
        Node* temp = head ;

        while(temp->nextPtr != tail){
            temp=temp->nextPtr;
        }

        temp->nextPtr=NULL;
        delete tail;
        tail=temp;
    }

    // PUSH BACK ADDING NEW AT ANY RANDOM POSTION

    void push_back_add_random_post(int val ,int post){
        Node* newNode = new Node(val);
        Node* temp =head;
        int curr_post=0;
        while(curr_post != post-1){
            temp=temp->nextPtr;
            curr_post++;
        }
        newNode->nextPtr=temp->nextPtr;
        temp->nextPtr=newNode;
    }

    // PUSH BACK UPDATE

    void push_back_update(int val , int post){
        int curr_post = 0 ;
        Node* newNode = new Node(val) ;
        Node* temp = head ;
        while(curr_post != post-1){
            temp = temp->nextPtr ; 
            curr_post++ ;
        }

        temp->data=val;
    }

};



int main(){
    List ll;

    // ll.push_front(1);
    // ll.push_front(2);
    // ll.push_front(3);

    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    // ll.pop_front();

    // ll.push_back_add_random_post(4,1);
    ll.push_back_update(4,3);

    ll.printLL();
    return 0 ;
}