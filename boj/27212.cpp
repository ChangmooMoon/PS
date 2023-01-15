#include <bits/stdc++.h>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
typedef long long ll;

int n, m, c, w[17][17], a[1001], b[1001];
ll d[1001][1001];

ll solve(int aIdx, int bIdx) {
    if (aIdx >= n || bIdx >= m) return 0;

    ll &ret = d[aIdx][bIdx];
    if (ret != -1) return ret;

    return ret = max({
               ret,
               solve(aIdx + 1, bIdx),
               solve(aIdx, bIdx + 1),
               solve(aIdx + 1, bIdx + 1) + w[a[aIdx]][b[bIdx]],
           });
}

int main() {
    FASTIO;
    cin >> n >> m >> c;
    for (int i = 1; i <= c; ++i) { // i-j 악수했을 때 만족도
        for (int j = 1; j <= c; ++j) {
            cin >> w[i][j];
        }
    }
    for (int i = 0; i < n; ++i) { // a 학생 성격정보
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) { // b 학생 성격정보
        cin >> b[i];
    }
    memset(d, -1, sizeof(d));
    cout << solve(0, 0);
    return 0;
}
