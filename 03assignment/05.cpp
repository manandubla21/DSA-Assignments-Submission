#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

int evaluatePostfix(string postfix) {
    stack<int> st;

    for (char c : postfix) {
        if (isdigit(c)) {
            st.push(c - '0'); 
        }

        else {
            int val2 = st.top(); st.pop();
            int val1 = st.top(); st.pop();

            switch (c) {
                case '+': st.push(val1 + val2); break;
                case '-': st.push(val1 - val2); break;
                case '*': st.push(val1 * val2); break;
                case '/': st.push(val1 / val2); break;
                case '^': {
                    int res = 1;
                    for (int i = 0; i < val2; i++) res *= val1;
                    st.push(res);
                    break;
                }
            }
        }
    }
    return st.top();
}

int main() {
    string postfix;
    cout << "Enter Postfix Expression: ";
    cin >> postfix;

    int result = evaluatePostfix(postfix);
    cout << "Result: " << result << endl;

    return 0;
}
