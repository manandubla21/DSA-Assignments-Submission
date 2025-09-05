#include <iostream>
#include <stack>
#include <string>
using namespace std;

void display(stack<int> st) {
    while (!st.empty()) {
        cout << (char)st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main() {
    string str = "DataStructure";
    stack<int> st;

    for(int i=0;i<str.size();i++) {
        st.push(str[i]);
    }

    while (!st.empty()) {
        cout << (char)st.top();
        st.pop();
    }

    display(st);

    return 0;
}