#include <bits/stdc++.h>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n, a[26];
string ans;

int main() {
    FASTIO;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        ++a[s[0] - 'a'];
    }

    for (int i = 0; i < 26; ++i) {
        if (a[i] >= 5) ans += 'a' + i;
    }

    if (ans.empty()) ans = "PREDAJA";
    cout << ans;
    return 0;
}
