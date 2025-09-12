#include <iostream>
using namespace std;

bool isFull(int n, int end) {
    return end == n - 1;
}

bool isEmpty(int front) {
    return front == -1;
}

void printArr(int *arr, int front, int end) {
    if (isEmpty(front)) {
        cout << "Queue is Empty!" << endl;
        return;
    }
    for (int i = front; i <= end; i++) cout << arr[i] << " ";
    cout << endl;
}

void enque(int *arr, int val, int n, int &front, int &end) {
    if (isFull(n, end)) {
        cout << "Queue is Full!" << endl;
        return;
    }
    if (isEmpty(front)) {
        front = 0;
    }
    end++;
    arr[end] = val;
}

void deque(int *arr, int n, int &front, int &end) {
    if (isEmpty(front) || front > end) {
        cout << "Queue is Empty!" << endl;
        front = -1;
        end = -1;
        return;
    }

    front++;
    if (front > end) {
        front = -1;
        end = -1;
    }
}

void peek(int *arr, int front, int end) {
    if (isEmpty(front)) {
        cout << "Queue is Empty!" << endl;
        return;
    }
    cout << "Front element is: " << arr[front] << endl;
}


int main() {
    int arr[10]; 
    int size = sizeof(arr) / sizeof(arr[0]);
    int front = -1;
    int end = -1;

    enque(arr, 1, size, front, end);
    enque(arr, 2, size, front, end);
    enque(arr, 3, size, front, end);
    printArr(arr, front, end);

    peek(arr, front , end);

    deque(arr, size, front, end);
    printArr(arr, front, end);

    deque(arr, size, front, end);
    deque(arr, size, front, end);
    printArr(arr, front, end);

    return 0;
}
