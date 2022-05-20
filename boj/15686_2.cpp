#include <bits/stdc++.h>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
#define INF 0x3f3f3f3f
typedef pair<int, int> pii;

int n, m, a[51][51], ans = INF;
vector<pii> home, chicken;
bool pick[13];

void go(int idx, int cnt) {
    if (cnt == m) {
        int ret = 0;
        for (pii h : home) {
            int minDist = INF;
            for (int i = 0; i < chicken.size(); ++i) {
                if (!pick[i]) continue;

                pii ch = chicken[i];
                int d = abs(h.first - ch.first) + abs(h.second - ch.second);
                minDist = min(minDist, d);
            }
            ret += minDist;
        }
        ans = min(ans, ret);
        return;
    }

    for (int i = idx; i < chicken.size(); ++i) {
        if (pick[i]) continue;
        pick[i] = true;
        go(i, cnt + 1);
        pick[i] = false;
    }
}

int main() {
    FASTIO;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            if (a[i][j] == 1)
                home.push_back({i, j});
            else if (a[i][j] == 2)
                chicken.push_back({i, j});
        }
    }
    go(0, 0);
    cout << ans;
    return 0;
}
