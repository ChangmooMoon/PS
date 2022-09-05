#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

bool solve(int n, int m) {
    int bit = 0;
    for (int i = 0; i < n; ++i) {
        bit += 1 << i;
    }
    return (m & bit) == bit;
}

int main() {
    FASTIO;
    int t, n, m;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cin >> n >> m;
        cout << '#' << i << ' ' << (solve(n, m) ? "ON" : "OFF") << endl;
    }
    return 0;
}
