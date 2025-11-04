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

class List {
    Node* head;

    public: 
    List() {
        head = NULL;
    }

    void reverseList() {
        if (head == NULL || head->next == NULL) return;

        Node* first = NULL;
        Node* second = head;
        Node* third = NULL;
        
        while(second != NULL) {
            third = second->next;
            second->next = first;
            first = second;
            second = third;
        }
        head = first;
    }

    void push_front(int val)
    {
        Node *temp = new Node(val);

        if (head == NULL) {
            head = temp;
            return;
        }
        else {
            temp->next = head;
            head = temp;
        }
    }

    void printLL()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    List ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_front(4);
    ll.push_front(5);
    ll.printLL();
    ll.reverseList();
    ll.printLL();
    return 0;
}