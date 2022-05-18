#include <bits/stdc++.h>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

string a, s, rs, x; // s + x + rs
map<char, int> cnt;

int main() {
    FASTIO;
    cin >> a;
    for (char ch : a) {
        ++cnt[ch];
    }

    bool stop = false;
    for (auto &[k, v] : cnt) {
        if (v & 1) {
            x = k;
            --v;
            if (stop) {
                cout << "I'm Sorry Hansoo";
                return 0;
            }
            stop = true;
        }
    }
    for (auto &[k, v] : cnt) {
        for (int i = 0; i < v / 2; ++i) {
            s += k;
        }
    }

    rs = s;
    reverse(rs.begin(), rs.end());
    cout << s + x + rs << endl;
    return 0;
}
