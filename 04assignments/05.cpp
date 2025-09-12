#include <iostream>
#include <queue>
using namespace std;

queue<int> q1, q2;

void pushTwoQueue(int x) {
    q2.push(x);                      // Step 1: push to q2
    while (!q1.empty()) {            // Step 2: move everything q1 → q2
        q2.push(q1.front());
        q1.pop();
    }
    swap(q1, q2);                    // Step 3: swap q1 and q2
}

void popTwoQueue() {
    if (q1.empty()) {
        cout << "Stack is Empty!" << endl;
        return;
    }
    cout << "Popped: " << q1.front() << endl;
    q1.pop();
}

void topTwoQueue() {
    if (q1.empty()) {
        cout << "Stack is Empty!" << endl;
        return;
    }
    cout << "Top element: " << q1.front() << endl;
}

void printStackTwoQueue() {
    if (q1.empty()) {
        cout << "Stack is Empty!" << endl;
        return;
    }

    queue<int> temp = q1;
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;
}

queue<int> q;

void pushOneQueue(int x) {
    q.push(x);
    int size = q.size();
    // Rotate to bring new element to the front
    for (int i = 0; i < size - 1; i++) {
        q.push(q.front());
        q.pop();
    }
}

void popOneQueue() {
    if (q.empty()) {
        cout << "Stack is Empty!" << endl;
        return;
    }
    cout << "Popped: " << q.front() << endl;
    q.pop();
}

void topOneQueue() {
    if (q.empty()) {
        cout << "Stack is Empty!" << endl;
        return;
    }
    cout << "Top element: " << q.front() << endl;
}

void printStackOneQueue() {
    if (q.empty()) {
        cout << "Stack is Empty!" << endl;
        return;
    }
    queue<int> temp = q;
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;
}

int main() {
    cout << "\nStack using Two Queues" << endl;
    pushTwoQueue(10);
    pushTwoQueue(20);
    pushTwoQueue(30);
    topTwoQueue();
    popTwoQueue();
    topTwoQueue();
    printStackTwoQueue();

    cout << "\nStack using One Queue" << endl;
    pushOneQueue(100);
    pushOneQueue(200);
    pushOneQueue(300);
    topOneQueue();
    popOneQueue();
    topOneQueue();
    printStackOneQueue();

    return 0;
}
