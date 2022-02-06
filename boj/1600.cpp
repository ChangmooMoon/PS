#include <cstring>
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
typedef tuple<int, int, int> tiii;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int dr8[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dc8[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int k, n, m;
int a[200][200];
int d[200][200][31];

int bfs(int sr, int sc) {  // 00 -> r-1, c-1
    queue<tiii> q;
    q.push({sr, sc, 0});
    d[sr][sc][0] = 0;

    while (!q.empty()) {
        int r, c, hmv;
        tie(r, c, hmv) = q.front();
        q.pop();

        for (int i = 0; i < 8; ++i) {
            if (hmv == k) break;
            int nr = r + dr8[i];
            int nc = c + dc8[i];
            if (0 > nr || 0 > nc || n <= nr || m <= nc || a[nr][nc]) continue;
            if (d[nr][nc][hmv + 1] != -1) continue;
            q.push({nr, nc, hmv + 1});
            d[nr][nc][hmv + 1] = d[r][c][hmv] + 1;
        }

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (0 > nr || 0 > nc || n <= nr || m <= nc || a[nr][nc]) continue;
            if (d[nr][nc][hmv] != -1) continue;
            q.push({nr, nc, hmv});
            d[nr][nc][hmv] = d[r][c][hmv] + 1;
        }
    }

    int ans = -1;
    for (int i = 0; i <= k; ++i) {
        int res = d[n - 1][m - 1][i];
        if (res == -1) continue;
        if (ans == -1 || ans > res) ans = res;
    }
    return ans;
}

int main() {
    FASTIO;
    cin >> k >> m >> n;  // 가로길이col, 세로길이row
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    memset(d, -1, sizeof(d));
    cout << bfs(0, 0);
    return 0;
}
