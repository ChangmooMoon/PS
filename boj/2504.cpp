#include <iostream>
#include <stack>
#include <string>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

// 괄호, 스택문제
int solve(string s) {
    stack<char> st;
    int ret = 0, tmp = 1;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '(') {
            tmp *= 2;
            st.push('(');
        } else if (s[i] == '[') {
            tmp *= 3;
            st.push('[');
        } else if (s[i] == ')') {
            if (st.empty() || st.top() != '(') return 0;
            if (s[i - 1] == '(') ret += tmp;
            st.pop();
            tmp /= 2;
        } else {
            if (st.empty() || st.top() != '[') return 0;
            if (s[i - 1] == '[') ret += tmp;
            st.pop();
            tmp /= 3;
        }
    }
    if (!st.empty()) return 0;
    return ret;
}

int main() {
    FASTIO;
    string s;
    cin >> s;
    cout << solve(s);
    return 0;
}
