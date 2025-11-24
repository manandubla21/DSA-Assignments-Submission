#include <iostream>
#include <string>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class CircularLinkedList {
    Node* head;
    Node* tail;

    public: 
    CircularLinkedList() {
        head = NULL;
        tail = NULL;
    }

    void insertAtTail(int data) {
        Node* newNode = new Node(data);

        if(head == NULL) {
            head = newNode;
            tail=head;
            return;
        }

        newNode->next = head;
        tail->next = newNode;
        tail = newNode;
    }

    void sizeOfCLL() {
        Node* temp = head;
        int size = 1;

        while( temp != tail) {
            temp = temp->next;
            size++;
        }

        cout << "Size of Circular linked list is : " << size << endl;
    }
    void printCLL() {
        Node* temp = head;

        while(temp != tail) {
            cout << temp->data << "->";
            temp= temp->next;
        }
        cout << tail->data << "->";
        cout << "NULL" << endl;
    }
};

int main() {
    CircularLinkedList cll;
    cll.insertAtTail(20);
    cll.insertAtTail(100);
    cll.insertAtTail(40);
    cll.insertAtTail(80);
    cll.insertAtTail(60);
    cll.sizeOfCLL();
    cll.printCLL();
    
    return 0;
}