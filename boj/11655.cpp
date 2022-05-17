#include <bits/stdc++.h>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int main() {
    FASTIO;
    string s, ans;
    getline(cin, s);
    for (char ch : s) {
        if (!isalpha(ch))
            ans += ch;
        else if (isupper(ch)) {
            ans += ('Z' < ch + 13 ? ch - 13 : ch + 13);
        } else {
            ans += ('z' < ch + 13 ? ch - 13 : ch + 13);
        }
    }
    cout << ans;
    return 0;
}
