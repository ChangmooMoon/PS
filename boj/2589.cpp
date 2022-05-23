#include <bits/stdc++.h>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
#define INF 0x3f3f3f3f

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int n, m, ans = 0;
string a[51]; // L W

int bfs(int sr, int sc) {
    queue<pair<int, int>> q;
    int d[51][51];
    memset(d, -1, sizeof(d));
    d[sr][sc] = 0;
    q.push({sr, sc});
    int ret = 0;

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (0 > nr || 0 > nc || n <= nr || m <= nc) continue;
            if (a[nr][nc] != 'L' || d[nr][nc] != -1) continue;

            d[nr][nc] = d[r][c] + 1;
            q.push({nr, nc});
            ret = max(ret, d[nr][nc]);
        }
    }

    return ret;
}

int main() {
    FASTIO;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 'L') ans = max(ans, bfs(i, j));
        }
    }

    cout << ans;
    return 0;
}
