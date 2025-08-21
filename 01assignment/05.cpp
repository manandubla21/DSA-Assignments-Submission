#include <iostream>
using namespace std;

int main() {
    //last problem
    int arr_2d[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    for(int i=0;i<3;i++) {
        int sum =0;
        for(int j=0;j<3;j++) {
            sum += arr_2d[i][j];
        }
        cout << "sum of " << i << " row is : " << sum << endl;
    }
    
    for(int i=0;i<3;i++) {
        int sum =0;
        for(int j=0;j<3;j++) {
            sum += arr_2d[j][i];
        }
        cout << "sum of " << i << " column is : " << sum << endl;
    }
    return 0;
}