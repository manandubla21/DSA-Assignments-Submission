#include <iostream>
#include <queue>
using namespace std;

void Operation(string str) {
    queue<char> q;
    string result = "";

    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];
        if (ch == ' ') continue;

        q.push(ch);

        while (!q.empty()) {
            char frontChar = q.front();
            int count = 0;

            for (int j = 0; j <= i; j++) {
                if (str[j] == frontChar) count++;
            }

            if (count > 1) {
                q.pop();
            } else {
                break;
            }
        }

        if (q.empty()) {
            cout << -1 << " ";
        } else {
            cout << q.front() << " ";
        }
    }
    cout << endl;
}

int main() {
    string input = "a a b c";
    cout << "Input: " << input << endl;
    cout << "Output: ";
    Operation(input);

    return 0;
}
