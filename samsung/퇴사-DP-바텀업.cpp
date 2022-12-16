#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int N, t[17], p[17], d[17], ans;

int main() {
    FASTIO;
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> t[i] >> p[i];
        d[i] = p[i];
    }

    for (int i = 2; i <= N; ++i) {
        for (int j = 1; j < i; ++j) {
            if (i >= j + t[j]) d[i] = max(d[i], d[j] + p[i]);
        }
    }

    for (int i = 1; i <= N; ++i) {
        if (i + t[i] <= N + 1 && ans < d[i]) ans = d[i];
    }
    cout << ans;
    return 0;
}
