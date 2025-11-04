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

    void deleteNode(int val) {
        if(head == NULL) {
            cout << "Linked list is empty" << endl;
            return;
        } else if(head->data == val) {
            head = head->next;
            return;
        }

        Node* temp = head;
        while(temp->next != NULL && temp->next->data != val) {
            temp = temp->next;
        }
        Node* keyVal = temp->next;
        temp->next = keyVal->next;
        keyVal->next = NULL;
    }

    void removeAllOccurances(int key) {
        if(head == NULL) {
            cout << "Linked list is empty" << endl;
        } else if(head->next == NULL) {
            return;
        }

        int count = 0;
        Node* curr = head;
        while(curr != NULL && curr->next != NULL) {
            if(curr->next->data == key) {
                Node* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
                count++;
            }
            curr = curr->next;
        }
        cout << "Number of occurances of " << key << " are " << count << endl;
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
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(1);
    ll.push_front(3);
    ll.push_front(1);
    ll.push_front(5);
    ll.printLL();
    ll.removeAllOccurances(1);
    ll.printLL();

    return 0;
}