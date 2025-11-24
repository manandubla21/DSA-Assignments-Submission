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

class LinkedList {
    public: 
    Node* head;

    LinkedList() {
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

    void checkCycle() {
        Node* slow = head;
        Node* fast = head;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) {
                cout << "Cycle detected" << endl;
                return;
            }

        }
        cout << "No cycle detected" << endl;
    }

    void printList() {
        Node* temp = head;

        while(temp != NULL) {
            cout << temp->data << "->";
            temp= temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList ll;
    ll.insertAtHead(1);
    ll.insertAtHead(2);
    ll.insertAtHead(3);
    ll.insertAtHead(9);
    ll.insertAtHead(5);
    ll.printList();
    ll.checkCycle();
    return 0;
}