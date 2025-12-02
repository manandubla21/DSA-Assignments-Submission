#include <iostream>
#include <string>
using namespace std;

void selectionSort(int arr[] , int n) {
    int end = n-1;
    for(int j=0;j<n;j++) {
        int smallest = j;
        int largest = end;

        for(int i=j;i<end+1;i++) {
            if(arr[i] <= arr[smallest]) {
                smallest = i;
            }
            if(arr[i] > arr[largest]) {
                largest = i;
            }
        }
        swap(arr[largest] , arr[end]);

        if(smallest == end) smallest = largest;

        swap(arr[smallest] , arr[j]);
        --end;
    }
}

void printArr(int arr[] , int n) {
    for (int i=0;i<n;i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {4 , 1 , 5 , 2 , 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr , n);
    printArr(arr , n);
    return 0;
}