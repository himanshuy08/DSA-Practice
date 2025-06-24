#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class LL {
    Node* head;

public:
    LL() {
        head = NULL;
    }

    // Insert at beginning
    void insert(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // Insert at end
    void push_back(int val) {
        Node* newNode = new Node(val);

        // If list is empty, new node becomes the head
        if (head == NULL) {
            head = newNode;
            return;
        }

        // Otherwise, go to the last node
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        // Link the last node to new node
        temp->next = newNode;
    }

    // Print the linked list
    void printList() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout <<"NULL" <<endl;
    }

    // Delete the beginning node
    void pop_front(){
        Node* temp = head;
        if(head==NULL){
            cout << "List is empty, nothing to delete." << endl;
            return;
        }
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    // delete last node
    void pop_back(){
        if (head == NULL) {
            cout << "List is empty, nothing to delete." << endl;
            return;
        }
        Node* temp = head;
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        delete temp->next; // delete last node
        temp->next = NULL;  
    }

    // search for a value
    int search(int val){
        Node* temp = head;
        int idx = 0;
        while(temp!=NULL){
            if(temp->data==val){
                return idx; // return index if found
            }
            temp = temp->next;
            idx++;
        }
        return -1; // return -1 if not found
    }
};

int main() {
    LL list;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(50);
    list.push_back(40);
    cout<<"Linked List after inserting elements at the beginning and end:" << endl;
    list.printList();
    cout<< "Deleting the first element:" << endl;
    list.pop_front();
    list.printList();
    cout<< "Deleting the last element:" << endl;
    list.pop_back();
    list.printList();
    return 0;
}
