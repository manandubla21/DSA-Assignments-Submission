#include <iostream>
#include <string>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class DoublyLinkedList {
    Node* head;

    public: 
    DoublyLinkedList() {
        head = NULL;
    }

    void insertAtHead(int data) {
        Node* newNode = new Node(data);
        if(head == NULL) {
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }

    void printDLL() {
        Node* temp = head;

        while(temp != NULL) {
            cout << temp->data << "->";
            temp= temp->next;
        }
        cout << "NULL" << endl;
    }

    void sizeOfDLL() {
        Node* temp = head;
        int size = 0;

        while(temp != NULL) {
            temp = temp->next;
            size++;
        }

        cout << "Size of Doubly linked list is : " << size << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    dll.insertAtHead(1);
    dll.insertAtHead(2);
    dll.insertAtHead(3);
    dll.insertAtHead(4);
    dll.insertAtHead(5);
    dll.printDLL();
    dll.sizeOfDLL();
    return 0;
}