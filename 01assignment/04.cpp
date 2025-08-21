#include <iostream>
using namespace std;


void reverse(int *arr,int n) {
    int start = 0;
    int end = n-1;
    while(start < end) {
        swap(arr[start],arr[end]);
        start++;
        end--;
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

void transpose(int arr[][3],int m , int n) {
    for(int i=0;i<m;i++) {
        for(int j=i+1;j<n;j++) {
            swap(arr[i][j], arr[j][i]);
        }
    }
}

void multiply(int A[][3], int B[][2], int C[][2], int m, int p, int n) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            C[i][j] = 0;
        }
    }

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < p; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    //reverse of a array
    cout << "reverse of a array" << endl;
    int arr02[10] = {1,2,3,4,5};
    int size = sizeof(arr02) / sizeof(arr02[0]);
    reverse(arr02,size);
    display(arr02,size);

    //multiply
    int A[2][3] = {{1,2,3},{4,5,6}};
    int B[3][2] = {{1,2},{3,4},{5,6}};
    int C[2][2];
    cout << "Multiplication" << endl;
    multiply(A,B,C,3,2,3);
    for(int i=0;i<2;i++) {
        for(int j=0;j<2;j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
    

    //transpose
    int arr_2d[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    cout << "transpose" << endl;
    transpose(arr_2d,3,3);
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            cout << arr_2d[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}