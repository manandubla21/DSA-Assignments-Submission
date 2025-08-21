#include <iostream>
using namespace std;

void deleteEle(int *arr, int idx) {
    int size = sizeof(arr) / sizeof(arr[0]);
    arr[idx-1] = -1;

    for(int i=idx;i<size-1;i++) {
        arr[i] = arr[i + 1];
    }
}

int main() {

    int arr[10] = {1,7,3,4,5,6,7,6,9,9};

    int count = 0;
    for(int i=0;i<10;i++) {
        for(int j=i+1;j<10;j++) {
            if(arr[i] == arr[j]) {
                deleteEle(arr,j+1);
            }
        }
    }

    for(int i=0;i<10;i++) {
        if (arr[i] < 0) continue;
        count++;
    }

    cout << count << endl;
    return 0;
}