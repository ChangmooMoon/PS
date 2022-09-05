#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

const int MOD = 1e9 + 7;

long long d[10001][16];
int t;
string s;

long long solve(string s) {
    memset(d, 0, sizeof(d));
    long long ret = 0;

    for (int i = 0; i < s.length(); ++i) {
        int key = 1 << (s[i] - 'A');

        for (int j = 1; j < (1 << 4); ++j) {
            if (i == 0) {
                if (j & key && j & 1) d[i][j] = 1;
            } else if (d[i - 1][j]) {
                for (int k = 1; k < (1 << 4); ++k) {
                    if (j & k && k & key) {
                        d[i][k] += d[i - 1][j];
                        d[i][k] %= MOD;
                    }
                }
            }
        }
    }

    for (int i = 1; i < (1 << 4); ++i) {
        ret += d[s.length() - 1][i];
        ret %= MOD;
    }
    return ret;
}

int main() {
    FASTIO;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cin >> s;
        cout << '#' << i << ' ' << solve(s) << endl;
    }

    return 0;
}
