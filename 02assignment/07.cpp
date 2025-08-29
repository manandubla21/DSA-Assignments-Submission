#include <iostream>
using namespace std;

int main() {
    int arr[4] = {2,6,4,3};
    int count =0 ;
    for(int i=0;i<4;i++) {
        for(int j=i+1;j<4;j++) {
            if(arr[i] > arr[j]) count++;
        }
    }

    cout << "Number of inversion in array are : " << count << endl;
    return 0;
}