#include <iostream>
using namespace std;

void tripletConversion(int arr[][3] , int row , int size) {
    int arr_2d[size][size];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            arr_2d[i][j] = 0;
        }
    }
    
    int r;
    int c;
    int val;
    for(int i=0;i<row;i++) {
        for(int j=0;j<3;j++) {
            if(j == 0) r=arr[i][j];
            else if(j == 1) c=arr[i][j];
            else val = arr[i][j];
        }
        arr_2d[r][c] = val;
    }
    for(int i=0;i<size;i++) {
        for(int j=0;j<size;j++) {
            cout << arr_2d[i][j] << " ";
        }
        cout << endl;
    }
}

void transpose() {
    int n;
    int size;
    cout << "Enter dimension of matrix : ";
    cin >> size;
    cout << "Enter number of non zero elements : ";
    cin >> n;
    int arr[n][3];
    cout << "Enter [ row , column , non-zero Value] : ";
    for(int i=0;i<n;i++) {
        for(int j=0;j<3;j++) {
            cin >> arr[i][j];
        }
    }

    cout << "Orginal Matrix -> " << endl;
    tripletConversion(arr,n,size);


    for(int i=0;i<n;i++) {
        swap(arr[i][0],arr[i][1]);
    }
    cout<<"Transpose Matrix -> " << endl;
    tripletConversion(arr,n,size);
}

void addition() {
    int size;
    cout << "Enter dimension of both matrix : ";
    cin >> size;

    int n1;
    cout << "Enter number of non zero elements in matrix1 : ";
    cin >> n1;
    int arr01[n1][3];
    cout << "Enter [ row , column , non-zero Value] : ";
    for(int i=0;i<n1;i++) {
        cin >> arr01[i][0] >> arr01[i][1] >> arr01[i][2];
    }

    int n2;
    cout << "Enter number of non zero elements in matrix 2 : ";
    cin >> n2;
    int arr02[n2][3];
    cout << "Enter [ row , column , non-zero Value] : ";
    for(int i=0;i<n2;i++) {
        cin >> arr02[i][0] >> arr02[i][1] >> arr02[i][2];
    }

    int ans[size][size];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            ans[i][j] = 0;
        }
    }
    
    for(int i=0;i<n1;i++) {
        int r = arr01[i][0];
        int c = arr01[i][1];
        ans[r][c] += arr01[i][2];
    }
    for(int i=0;i<n2;i++) {
        int r = arr02[i][0];
        int c = arr02[i][1];
        ans[r][c] += arr02[i][2];
    }

    cout << "Addition of both matrix is : ";
    for(int i=0;i<size;i++) {
        for(int j=0;j<size;j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

void multiplication() {
    int size;
    cout << "Enter dimension of both matrix : ";
    cin >> size;

    int n1;
    cout << "Enter number of non zero elements in matrix1 : ";
    cin >> n1;
    int arr01[n1][3];
    cout << "Enter [ row , column , non-zero Value] : ";
    for(int i=0;i<n1;i++) {
        cin >> arr01[i][0] >> arr01[i][1] >> arr01[i][2];
    }

    int n2;
    cout << "Enter number of non zero elements in matrix 2 : ";
    cin >> n2;
    int arr02[n2][3];
    cout << "Enter [ row , column , non-zero Value] : ";
    for(int i=0;i<n2;i++) {
        cin >> arr02[i][0] >> arr02[i][1] >> arr02[i][2];
    }

    int ans[size][size];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            ans[i][j] = 0;
        }
    }
    
    for(int i=0;i<n1;i++) {
    int r1 = arr01[i][0];   
    int c1 = arr01[i][1];   
    int v1 = arr01[i][2];   

    for(int j=0;j<n2;j++) {
        int r2 = arr02[j][0];
        int c2 = arr02[j][1]; 
        int v2 = arr02[j][2]; 

        if(c1 == r2) {
            ans[r1][c2] += v1 * v2;
        }
    }
}

    cout << "Multiplication of both matrix is : " << endl;
    for(int i=0;i<size;i++) {
        for(int j=0;j<size;j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    // transpose();
    // addition();
    multiplication();
    return 0;
}