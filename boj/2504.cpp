#include <iostream>
#include <stack>
#include <string>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int solve(string s) {
    int ret = 0, mul = 1;
    stack<char> st;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '(') {
            st.push('(');
            mul *= 2;
        } else if (s[i] == '[') {
            st.push('[');
            mul *= 3;
        } else if (s[i] == ')') {
            if (st.empty() || st.top() != '(') return 0;
            st.pop();
            if (s[i - 1] == '(') ret += mul;
            mul /= 2;
        } else if (s[i] == ']') {
            if (st.empty() || st.top() != '[') return 0;
            st.pop();
            if (s[i - 1] == '[') ret += mul;
            mul /= 3;
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
