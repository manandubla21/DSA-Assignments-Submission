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

    void insertAtHead(int data) {
        Node* newNode = new Node(data);
        if(head == NULL) {
            head = newNode;
            tail = head;
            return;
        }
        newNode->next = head;
        tail->next = newNode;
        head = newNode;
    }

    void insertAtTail(int data) {
        Node* newNode = new Node(data);

        if(head == NULL) {
            newNode = head;
            tail = head;
            return;
        }

        newNode->next = head;
        tail->next = newNode;
        tail = newNode;
    }

    void insertAtIndex(int data , int pos) {
        Node* newNode = new Node(data);
        
        if(head == NULL) {
            newNode = head;
            tail = head;
            return;
        }
        
        int count = 1;
        Node* temp = head;
        while(count != pos-1 && temp->next != NULL) {
            temp = temp->next;
            count++;
        }

        newNode->next = temp->next;
        temp->next = newNode; 
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
    CircularLinkedList cll;
    cll.insertAtHead(1);
    cll.insertAtHead(2);
    cll.insertAtHead(3);
    cll.insertAtTail(4);
    cll.insertAtIndex(8,3);
    cll.deleteNode(8);
    cll.printCLL();
    cll.Search(1);
    
    return 0;
}