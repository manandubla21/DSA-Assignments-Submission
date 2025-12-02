#include <iostream>
#include <string>
#include <vector>
using namespace std;

void printArr(int arr[] , int n) {
    for(int i=0;i<n;i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void selectionSort(int arr[] , int n) {
    for(int j=0;j<n;j++) {
        int smallest = j;
        for(int i=j+1;i<n;i++) {
            if(arr[i] <= arr[smallest]) {
                smallest = i;
            }
        }
        swap(arr[smallest] , arr[j]);
    }
}

// void insertionSort(int arr[] , int n) {
//     for(int i=1;i<n;i++) {
//         int curr = i;
//         for(int j=i-1;j>=0;j--) {
//             if(arr[curr] < arr[j]) {
//                 swap(arr[j] , arr[curr--]);
//             }
//         }
//     }
// }
//My new version of insertion sort


void insertionSort(int arr[] , int n) {
    for(int i=1;i<n;i++) {
        int curr = arr[i];
        int prev = i-1;
        while( prev >= 0 && arr[prev] > curr) {
            arr[prev+1] = arr[prev];
            prev--;
        }
        arr[prev+1] = curr; //placing curr ele in correct pos
    }
}

void bubbleSort(int arr[] , int n) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<n-i;j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j+1] , arr[j]);
            }
        }
    }
}

void merge(int arr[] , int start , int mid , int end) {
    vector<int> temp;
    int i = start;
    int j = mid+1;
    while(i <= mid && j <= end) {
        if(arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
        }
    }

    while(i <= mid) {
        temp.push_back(arr[i++]);
    }
    while(j <= end) {
        temp.push_back(arr[j++]);
    }

    for(int i=0;i<temp.size();i++) {
        if(temp[i] != 0) {
            arr[i+start] = temp[i];
        }
    }
}

void mergeSort(int arr[] , int start , int end) {
    
    if(start < end) {
        int mid = start +(end - start) / 2;
        
        mergeSort(arr , start , mid);
        mergeSort(arr , mid+1 , end);

        merge(arr , start , mid , end);
    }
}

int partition(int arr[] ,int start , int end) {
    int idx = start-1;
    int pivot = arr[end];

    for(int j=start;j<end;j++) {
        if(arr[j] <= pivot) {
            idx++;
            swap(arr[j] , arr[idx]);
        }
    }
    swap(arr[end] , arr[idx+1]);
    return idx;
}

void quickSort(int arr[] , int start , int end) {
    if(start < end) {
        int pivot_idx = partition(arr , start , end);

        quickSort(arr , start , pivot_idx-1);
        quickSort(arr , pivot_idx+1 , end);
    }
}
int main() {
    int arr[] = {4 , 1 , 5 , 2 , 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr , size);
    printArr(arr , size);

    insertionSort(arr , size);
    printArr(arr , size);

    bubbleSort(arr , size);
    printArr(arr , size);

    mergeSort(arr , 0 , size-1);
    printArr(arr , size);

    quickSort(arr , 0 , size-1);
    printArr(arr , size);

    return 0;
}