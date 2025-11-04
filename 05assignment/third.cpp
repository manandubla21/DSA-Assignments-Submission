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

    Node* middleOfList() {
        Node* slow = head;
        Node* fast = head;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
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
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.push_front(0);
    ll.printLL();
    cout << "middle of the linked list is " << (ll.middleOfList())->data << endl;
    return 0;
}