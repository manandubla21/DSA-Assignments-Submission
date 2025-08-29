#include <iostream>
using namespace std;

int main() {
    int r;
    cout << "Enter number of rows in array : ";
    cin >> r;
    int c;
    cout << "Enter number of columns in array : ";
    cin >> c;

    int arr[r][c];
    cout << "Enter elements in row major : ";

    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            cin >> arr[i][j];
        }
    }
    bool found = false;
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            bool saddle = true;
            int num = arr[i][j];

            for (int k = 0; k < r; k++) {
                if (arr[k][j] > num) {
                    saddle = false;
                    break;
                }
            }

            for (int m = 0; m < c && saddle; m++) {
                if (arr[i][m] < num) {
                    saddle = false;
                    break;
                }
            }

            if(saddle) {
                cout << num << " is a saddle point! at " << i << " and " << j << " index" << endl;
                found = true;
            }
        }
    }
    if(!found) cout << "There is no saddle point in the array! ---OOPs---" << endl;
    return 0;
}

// 1 2 6 8 9 7 3 4 5