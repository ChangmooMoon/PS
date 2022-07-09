#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
#define INF 0x3f3f3f3f

int n, m, a[1005][1005], d[1005][1005], d2[1005][1005];

int main() {
    FASTIO;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= m; ++j) {
            if (i == n)
                d[i][j] = d[i][j - 1] + a[i][j];
            else if (j == 1)
                d[i][j] = d[i + 1][j] + a[i][j];
            else
                d[i][j] = max(d[i + 1][j], d[i][j - 1]) + a[i][j];
        }
    }

    for (int i = n; i >= 1; --i) {
        for (int j = m; j >= 1; --j) {
            if (i == n)
                d2[i][j] = d2[i][j + 1] + a[i][j];
            else if (j == m)
                d2[i][j] = d2[i + 1][j] + a[i][j];
            else
                d2[i][j] = max(d2[i + 1][j], d2[i][j + 1]) + a[i][j];
        }
    }

    int ans = -INF;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            ans = max(ans, d[i][j] + d2[i][j]);
        }
    }
    cout << ans;
    return 0;
}
