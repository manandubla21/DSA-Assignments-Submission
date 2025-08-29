#include <iostream>
#include <vector>
using namespace std;

void diagonal() {
    int n;
    cout << "Enter number of rows and colums : " << endl;
    cin >> n;
    int arr[n];
    cout << "Enter elements of diagonal : " << endl;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(i==j) cout << arr[i] << " ";
            else cout << "0" << " ";
        }
        cout << endl;
    }
}

void triDiagonal() {
    int n;
    cout << "Enter number of rows and colums : " << endl;
    cin >> n;
    int arr[n];
    cout << "Enter elements of diagonal in row major: " << endl;
    for(int i=0;i<(3*n)-2;i++) {
        cin >> arr[i];
    }

    int idx=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(i==j || i-j==-1 || i-j==1) cout << arr[idx++] << " ";
            else cout << "0" << " ";
        }
        cout << endl;
    }
}

void upperTriangularMatrix() {
    int n;
    cout << "Enter number of rows and colums : " << endl;
    cin >> n;
    int arr[n];
    cout << "Enter elements of Upper Triangular matrix in row major: " << endl;
    for(int i=0;i<(n*(n+1))/2;i++) {
        cin >> arr[i];
    }

    int idx = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(i<=j) cout << arr[idx++] << " ";
            else cout << "0" << " ";
        }
        cout << endl;
    }

}
void lowerTriangularMatrix() {
    int n;
    cout << "Enter number of rows and colums : " << endl;
    cin >> n;
    int arr[n];
    cout << "Enter elements of Upper Triangular matrix in row major: " << endl;
    for(int i=0;i<(n*(n+1))/2;i++) {
        cin >> arr[i];
    }

    int idx = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(i>=j) cout << arr[idx++] << " ";
            else cout << "0" << " ";
        }
        cout << endl;
    }
}

void symmetricMatrix() {
    int n;
    cout << "Enter number of rows and columns: ";
    cin >> n;

    int size = (n * (n + 1)) / 2;  // number of elements in upper triangle
    vector<int> arr(size);

    cout << "Enter " << size << " elements of upper triangle (row-wise):" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    // Function to map (i, j) → index in arr
    auto index = [&](int i, int j) {
        return (i * n - (i * (i - 1)) / 2) + (j - i);
    };

    // Print the symmetric matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j >= i) {
                cout << arr[index(i, j)] << " "; // upper triangle
            } else {
                cout << arr[index(j, i)] << " "; // lower triangle (symmetric)
            }
        }
        cout << endl;
    }
}

int main() {
    // diagonal();
    // triDiagonal();
    // upperTriangularMatrix();
    // lowerTriangularMatrix();
    symmetricMatrix();
    return 0;
}