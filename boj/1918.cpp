#include <cctype>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int priority(char a) {
    if (a == '(')
        return 0;
    if (a == '+' || a == '-')
        return 1;
    return 2;
}

int main() {
    string expr;
    cin >> expr;
    stack<char> st;

    for (char ch : expr) {
        if (isalpha(ch)) {
            cout << ch;
        } else if (ch == '(') {
            st.push(ch);
        } else if (ch == ')') {
            while (st.top() != '(') {
                cout << st.top();
                st.pop();
            }
            st.pop();
        } else {
            while (!st.empty() && priority(ch) <= priority(st.top())) {
                cout << st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }
    return 0;
}