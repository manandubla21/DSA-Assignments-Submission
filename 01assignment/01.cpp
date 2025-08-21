#include <iostream>
using namespace std;

void display(int *arr, int n) {
    for(int i=0;i<n;i++) {
        if(arr[i] != 0)  {

            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

void insert(int *arr,int n,int val,int pos) {
    for(int i=n-1;i>=pos-1;i--) {
        if(arr[i] != 0) {
            swap(arr[i],arr[i+1]);
        }
    }
    arr[pos-1] = val;
}

void deleteEle(int *arr,int n,int pos) {
    arr[pos-1] = 0;
    for(int i=pos-1;i<n-1;i++) {
        swap(arr[i],arr[i+1]);
    }
}

int linearSearch(int *arr,int n, int val) {
    for(int i=0;i<n;i++) {
        if(arr[i] == val) {
            return i;
        }
    }
}

int main() {
    //Create
    int arr[10] = {1,2,3,4,5};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    //display
    display(arr,size);

    //insert
    insert(arr,size,10,2);
    display(arr,size);

    //delete
    deleteEle(arr,size,2);
    display(arr,size);

    cout << "val is present at index : " << linearSearch(arr,size,3)+1 << endl;
    return 0;
}