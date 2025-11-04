#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class List
{
    Node *head;

public:
    List()
    {
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

    void push_back(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL) {
            head = newNode;
            return;
        }
            Node *temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
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

    void pop_front() {
        if(head == NULL) {
            cout << "Linked List is empty" << endl;
            return;
        }

        head = head->next;
    }

    void pop_back() {
        if(head == NULL) {
            cout << "Linked list is empty" << endl;
            return;
        }

        Node* temp = head;
        while(temp->next->next != NULL) {
            temp = temp->next;
        }
        temp->next = NULL;
    }

    void deleteNode(int val) {
        if(head == NULL) {
            cout << "Linked list is empty" << endl;
            return;
        } else if(head->data == val) {
            pop_front();
            return;
        }

        Node* temp = head;
        while(temp->next->data != val && temp->next != NULL) {
            temp = temp->next;
        }
        Node* keyVal = temp->next;
        temp->next = keyVal->next;
        keyVal->next = NULL;
    }

    void search(int val) {
        Node* temp = head;
        int count = 1;
        while(temp->next != NULL && temp->data != val) {
            temp = temp->next;
            count++;
        }

        cout << val << " is present at index " << count << endl;
    }

    void insert(int val , bool after ,int given) {
        Node* newNode = new Node(val);

        if(head == NULL) {
            head = newNode;
        }

        if(after) {
            Node* temp = head;
            while(temp->data != given) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        } else {
            Node* temp = head;
            while(temp->next->data != given) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
};

int main()
{
    List ll;

    ll.push_front(1);
    ll.push_front(2);
    ll.push_back(3);

    ll.insert(4,0,1);
    ll.pop_front();
    ll.pop_back();
    ll.deleteNode(4);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.search(3);
    ll.printLL();
    return 0;
}