#include <iostream>
using namespace std;

int missingNum(int *arr) {
    for(int i=0;i<9;i++) {
        if(arr[i+1] - arr[i] != 1) return arr[i]+1;
    }
    return -1;
}

int main() {
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};

    cout << "Missing number in sorted array is : "<< missingNum(arr)<< endl;
    return 0;
}