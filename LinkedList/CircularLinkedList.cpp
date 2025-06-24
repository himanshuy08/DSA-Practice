#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node(int value) {
            data = value;
            next = nullptr;
        }
};

class CircularLinkedList {
    private:
        Node* head;

    public:
        CircularLinkedList() {
            head = nullptr;
        }

        void insert(int value) {
            Node* newNode = new Node(value);
            if (head == nullptr) {
                head = newNode;
                newNode->next = head; // Point to itself
            } else {
                Node* temp = head;
                while (temp->next != head) {
                    temp = temp->next;
                }
                temp->next = newNode;
                newNode->next = head; // Complete the circle
            }
        }

        void display() {
            if (head == nullptr) return;

            Node* temp = head;
            do {
                cout << temp->data << "<->";
                temp = temp->next;
            } while (temp != head);
            cout<<endl;
        }
};

int main(){
    CircularLinkedList cll;
    cll.insert(10);
    cll.insert(20);
    cll.insert(30);
    cll.display(); // Output: 10 20 30

    return 0;
}