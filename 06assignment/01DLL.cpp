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

    void insertAtTail(int data) {
        Node* newNode = new Node(data);

        Node* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    void insertAtIndex(int data , int pos) {
        Node* newNode = new Node(data);
        
        if(head == NULL) {
            newNode = head;
            return;
        }
        
        int count = 1;
        Node* temp = head;
        while(count != pos-1 && temp->next != NULL) {
            temp = temp->next;
            count++;
        }

        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next = newNode;
        newNode->next->prev = newNode; 
    }

    void printDLL() {
        Node* temp = head;

        while(temp != NULL) {
            cout << temp->data << "->";
            temp= temp->next;
        }
        cout << "NULL" << endl;
    }

    void deleteNode(int val) {
        Node* temp = head;

        if(head == NULL) {
            cout << "Linked List is empty" << endl;
            return;
        }

        if(head->next == NULL) {
            head = NULL;
            return;
        }

        while(temp->next != NULL && temp->next->data != val) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << "Value not found\n";
            return;
        }
        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        toDelete->next->prev = temp;
    }

    void Search(int data) {
        Node* temp = head;
        int count = 1;
        while(temp->next != NULL && temp->data != data) {
            temp = temp->next;
            count++;
        }
        if(count > 0) {
            cout << "value found at index " << count << endl;
        }
    }
};

int main() {
    DoublyLinkedList dll;
    dll.insertAtHead(1);
    dll.insertAtTail(2);
    dll.insertAtTail(3);
    dll.insertAtTail(4);
    dll.insertAtIndex(5 , 2);
    dll.deleteNode(5);
    dll.printDLL();
    dll.Search(2);
    return 0;
}