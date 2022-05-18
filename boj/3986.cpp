#include <bits/stdc++.h>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int t, ans = 0;
string s;

bool solve(string s) {
    stack<char> st;
    for (char ch : s) {
        if (!st.empty() && st.top() == ch)
            st.pop();
        else
            st.push(ch);
    }

    return st.empty();
}

int main() {
    FASTIO;
    cin >> t;
    while (t--) {
        cin >> s;
        if (solve(s)) ++ans;
    }

    cout << ans;
    return 0;
}
