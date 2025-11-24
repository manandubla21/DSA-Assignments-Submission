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

    bool isPalindrome() {
        Node* end = head;
        Node* start = head;

        if(head == NULL || head->next == NULL) {
            return true;
        }

        while(end->next != NULL) {
            end = end->next;
        }

        while (start != end && end->next != start) {
            if(start->data != end->data) {
                return false;
            }
            start = start->next;
            end = end->prev;
        }
        return true;
    }
};

int main() {
    DoublyLinkedList dll;
    dll.insertAtHead(1);
    dll.insertAtHead(2);
    dll.insertAtHead(3);
    dll.insertAtHead(2);
    dll.insertAtHead(1);
    dll.printDLL();
    if(dll.isPalindrome()) {
        cout << "Linked list is a Palindrome";
    } else {
        "Linked list is not a palindrome";
    }
    return 0;
}