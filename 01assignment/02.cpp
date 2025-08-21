#include <iostream>
using namespace std;

void deleteEle(int *arr,int n,int pos) {
    arr[pos-1] = 0;
    for(int i=pos-1;i<n-1;i++) {
        swap(arr[i],arr[i+1]);
    }
}

void removeDuplicate(int *arr,int n) {
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            if(arr[i] == arr[j]) {
                deleteEle(arr,n,j+1);
            }
        }
    }
}

void display(int *arr, int n) {
    for(int i=0;i<n;i++) {
        if(arr[i] != 0)  {

            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

int main() {
    //duplicate elements
    int arr01[7] = {1,2,3,2,4,5,3};
    removeDuplicate(arr01,7);
    display(arr01,7);
    return 0;
}