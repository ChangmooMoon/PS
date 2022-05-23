#include <bits/stdc++.h>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int n, m, sr, sc;
string a[1001];
queue<tuple<int, int, int>> q; // r, c, type
int d[1001][1001];

int bfs(int sr, int sc) {
    q.push({sr, sc, 0}); // 사람
    d[sr][sc] = 1;

    while (!q.empty()) {
        auto [r, c, type] = q.front(); // type 0 사람, 1 불
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (0 > nr || 0 > nc || n <= nr || m <= nc) {
                if (type == 1) continue;
                return d[r][c];
            }
            if (d[nr][nc] || a[nr][nc] == '#') continue;
            q.push({nr, nc, type});
            d[nr][nc] = d[r][c] + 1;
        }
    }
    return -1;
}

int main() {
    FASTIO;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 'J') {
                sr = i, sc = j;
            } else if (a[i][j] == 'F') {
                q.push({i, j, 1}); // 불
                d[i][j] = 1;
            }
        }
    }

    int ans = bfs(sr, sc);
    if (ans == -1)
        cout << "IMPOSSIBLE";
    else
        cout << ans;
    return 0;
}
