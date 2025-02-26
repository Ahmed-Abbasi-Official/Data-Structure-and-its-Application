#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *nextPtr;

    // Constructor to initialize the node
    Node(int val)
    {
        data = val;
        nextPtr = NULL;
    }
};

class List
{
    Node *head;
    Node *tail;

public:
    List()
    {
        head = tail = NULL;
    }

    // * POP FRONT

    void pop_front()
    {
        Node *temp = head;
        head = head->nextPtr;
        temp->nextPtr = NULL;

        delete temp;
    }

    // * PUSH FRONT

    void push_front(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }
        else
        {
            newNode->nextPtr = head;
            head = newNode;
        }
    }

    // * PRINT ALL

    void printLL()
    {
        Node *temp = head;

        while (temp != NULL)
        {
            cout << " " << temp->data << " ";
            temp = temp->nextPtr;
        }
        cout << endl;
    }

    // * PUSH BACK

    void push_back(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
            // newNode->nextPtr=head;
            return;
        }
        else
        {
            tail->nextPtr = newNode;
            tail = newNode;
        }
    }

    // * POP BACK

    void pop_back()
    {
        Node *temp = head;

        while (temp->nextPtr != tail)
        {
            temp = temp->nextPtr;
        }

        temp->nextPtr = NULL;
        delete tail;
        tail = temp;
    }

    // * PUSH BACK ADDING NEW AT ANY RANDOM POSTION

    void push_back_add_random_post(int val, int post)
    {
        Node *newNode = new Node(val);
        Node *temp = head;
        int curr_post = 0;
        while (curr_post != post - 1)
        {
            temp = temp->nextPtr;
            curr_post++;
        }
        newNode->nextPtr = temp->nextPtr;
        temp->nextPtr = newNode;
    }

    // * PUSH BACK UPDATE

    void push_back_update(int val, int post)
    {
        int curr_post = 0;
        Node *newNode = new Node(val);
        Node *temp = head;
        while (curr_post != post - 1)
        {
            temp = temp->nextPtr;
            curr_post++;
        }

        temp->data = val;
    }

    // * SEARCH

    int search(int val)
    {
        Node *temp = head;
        int idx = 0;
        while (temp != NULL)
        {
            if (temp->data == val)
            {
                return idx + 1;
            }
            temp = temp->nextPtr;
            idx++;
        }
        return -1;
    }

    // * DELETE EVERY ALTERNATE ELEMENT FORM LIST STARTING SECOND LAST ELEMENT

    void deleteAlternateNodes()
    {
        Node *curr_node = head;
        while (curr_node != NULL && curr_node->nextPtr != NULL)
        {
            /* code */
            Node *temp = curr_node->nextPtr;
            curr_node->nextPtr = curr_node->nextPtr->nextPtr;
            delete temp;
            curr_node = curr_node->nextPtr;
        }
    }

    // * REVERSE LINKED LIST

    void reverseLinkList()
    {
        Node *currNode = head;
        Node *prev = NULL;
        Node *next = NULL;

        while (currNode != NULL)
        {
            next = currNode->nextPtr;
            currNode->nextPtr = prev;
            prev = currNode;
            currNode = next;
        }
        head = prev;
    }

    // * FIND MIDDLE OF LINKED LIST

    void middelofList(){
        // BY FAST AND SLOW APPROACH
        Node* slow = head;
        Node* fast = head;

        while(fast !=NULL && fast->nextPtr != NULL){
            slow=slow->nextPtr;
            fast=fast->nextPtr->nextPtr;
        }
        cout<<"Middle value is : "<<slow->data;
    }

    // * DETECT LOOP IN LIST

    bool detectLoopInList(){
        Node* slow = head;
        Node* fast = head;
        while(fast!=NULL && fast->nextPtr !=NULL){
            if(fast=slow){
                return true;
                break;
            }
            slow = slow->nextPtr;
            fast=fast->nextPtr->nextPtr;
        }
        return false;
    }

    // * DETECT AND DELETE LOOP

    Node* detectAndDeleteCyle(){
        Node* slow = head;
        Node* fast=head;
        bool isCycle=false;

        while(fast != NULL && fast->nextPtr != NULL){
            slow=slow->nextPtr;
            fast=fast->nextPtr->nextPtr;
            if(slow == fast){
                isCycle=true;
                break;
            };
        };
        if(!isCycle){
            return NULL;
        };
        slow=head;
        while (slow==fast){
            slow=slow->nextPtr;
            fast=fast->nextPtr;
        }

        return slow->nextPtr;

    }

    //  * DELETE ANY SPECIFIC VALUE ;

    void deleteValue (int val){
        Node* temp= head;

        while(temp->nextPtr->data != val){
           temp=temp->nextPtr;
        }

        Node* prev = temp->nextPtr;
        temp->nextPtr=temp->nextPtr->nextPtr;
        delete prev;
    };


};

int main()
{
    List ll;

    // ll.push_front(1);
    // ll.push_front(2);   
    // ll.push_front(3);
    // ll.push_front(4);
    // ll.push_front(5);
    // ll.push_front(6);

    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);
    ll.push_back(6);
    // ll.pop_front();

    // ll.push_back_add_random_post(4,1);
    // ll.push_back_update(4,3);
    // ll.pop_back();
    // cout<<ll.search(2)<<endl;
    //  ll.deleteAlternateNodes();
    // ll.reverseLinkList();
    // ll.middelofList();

    // ll.deleteValue(3);

    ll.printLL();

    return 0;
}