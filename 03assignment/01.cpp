#include <iostream>
using namespace std;

void display(int *arr , int &n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void push(int *arr, int num, int size, int &n) {
    if (n == size) {
        cout << "Array is full!" << endl;
        return;
    }

    for (int i = n - 1; i >= 0; i--) {
        arr[i + 1] = arr[i];
    }

    arr[0] = num;
    n++; 
}

void pop(int *arr , int size , int &n) {
    n--;
}

bool isEmpty(int *arr , int size , int &n) {
    if(n == 0) return true;
    return false;
}

bool isFull(int *arr ,int size , int &n) {
    if(n == size) return true;
    return false;
}

int peek(int *arr) {
    return arr[0];
}

int main() {
    int arr[5] = {1, 2, 3};
    int n = 3;     
    int size = 5;  

    push(arr, 10, size, n);
    display(arr, n);

    pop(arr, size , n);
    display(arr,n);

    if(isEmpty(arr,size,n)) cout << "Stack is Empty" << endl;
    else cout << "Stack is not empty" << endl;

    if(isEmpty(arr,size,n)) cout << "Stack is Full" << endl;
    else cout << "Stack is not full" << endl;

    cout << peek(arr) << endl;
    return 0;
}
