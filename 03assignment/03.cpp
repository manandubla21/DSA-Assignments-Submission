#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool checkParanthesis(string str) {
    stack<int> st;

    for(char ch : str) {
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        }
        
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (st.empty()) return false;

            char top = st.top();
            st.pop();

            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
        }
        
    }

    return st.empty();
}

int main() {
    string str = "{([])}";

    if(checkParanthesis(str)) cout << "Equal Paranthesis";
    else cout << "Not Equal paranthesis";
    return 0;
}