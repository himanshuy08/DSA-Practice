#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int val){
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyList{
    Node* head;
    Node* tail;

    public:
    DoublyList(){
        head = nullptr;
        tail = nullptr;
    };

    // Insert at beginning
    void push_front(int val){
        Node* newNode = new Node(val);
        if(head== nullptr){
            head = tail = newNode;
        }else{
            newNode->next=head;
            head->prev= newNode;
            head=newNode;
        }
    }

    //Print the doubly linked list
    void printList(){
        Node* temp = head;
        while(temp!= nullptr){
            cout<<temp->data<<" <-> ";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }

    // insert at end
    void push_back(int val){
        Node* newNode = new Node(val);
        if(tail == nullptr){
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Delete the beginning node
    void pop_front(){
        Node* temp = head;
        if(head == nullptr) return; // List is empty
        if(head == tail) { // Only one node
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        temp->next = nullptr; // Clear the next pointer
        delete temp; // Free the memory
    }
    void pop_back(){
        Node* temp = tail;
        if(tail == nullptr) return; // List is empty
        if(head == tail) { // Only one node
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        temp->prev = nullptr; // Clear the previous pointer
        delete temp; // Free the memory
    }
};

int main(){
    DoublyList dl;
    dl.push_front(10);
    dl.push_front(20);
    dl.push_front(30);
    dl.printList(); // Output: 30 <-> 20 <-> 10 <->

    dl.push_back(40);
    dl.push_back(50);
    dl.printList(); // Output: 30 <-> 20 <-> 10 <-> 40 <-> 50 <-> NULL

    dl.pop_front();
    dl.printList(); // Output: 20 <-> 10 <-> 40 <-> 50 <-> NULL

    dl.pop_back();
    dl.printList(); // Output: 20 <-> 10 <-> 40 <-> NULL
    return 0;
}