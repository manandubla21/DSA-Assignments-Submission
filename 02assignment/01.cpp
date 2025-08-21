#include <iostream>
using namespace std;

int main() {
    int arr[10] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int target = 56;
    int size = sizeof(arr) / sizeof(arr[0]);

    int start=0;
    int end = size-1;

    while(start <= end) {    // O(log n)
        int mid = start + (end - start) / 2;
        if(arr[mid] > target) {
            end = mid-1;
        } else if(arr[mid] < target) {
            start = mid+1;
        } else {
            cout << "target is found at index : " << mid+1 << endl;
            return 0;
        }
    }

    cout << "Target not found" << endl;
    return 0;
}
