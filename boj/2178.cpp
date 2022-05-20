#include <bits/stdc++.h>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int n, m, a[101][101], d[101][101];

int bfs(int sr, int sc, int er, int ec) {
    memset(d, -1, sizeof(d));

    queue<pair<int, int>> q;
    q.push({sr, sc});
    d[sr][sc] = 1;

    while (!q.empty()) {
        const auto [r, c] = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (0 > nr || 0 > nc || n <= nr || m <= nc) continue;
            if (!a[nr][nc] || d[nr][nc] != -1) continue;

            q.push({nr, nc});
            d[nr][nc] = d[r][c] + 1;
            if (nr == er && nc == ec) return d[nr][nc];
        }
    }

    return -1;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%1d", &a[i][j]);
        }
    }

    cout << bfs(0, 0, n - 1, m - 1);
    return 0;
}
