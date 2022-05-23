#include <bits/stdc++.h>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int N, L, R, ans = 0, a[51][51], d[51][51];
bool stop;

bool bfs(int sr, int sc, int color) {
    int total = a[sr][sc];
    int cnt = 1;
    queue<pair<int, int>> q;
    q.push({sr, sc});
    d[sr][sc] = color;
    vector<pair<int, int>> route = {{sr, sc}};

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (0 > nr || 0 > nc || N <= nr || N <= nc || d[nr][nc] != -1) continue;

            int diff = abs(a[nr][nc] - a[r][c]);
            if (L <= diff && diff <= R) {
                q.push({nr, nc});
                d[nr][nc] = color;
                total += a[nr][nc];
                ++cnt;
                route.push_back({nr, nc});
            }
        }
    }

    for (auto &[r, c] : route) {
        a[r][c] = total / cnt;
    }

    return cnt > 1;
}

int main() {
    FASTIO;
    cin >> N >> L >> R;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> a[i][j];
        }
    }

    while (1) {
        bool stop = true;
        int color = 0;

        memset(d, -1, sizeof(d));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (d[i][j] == -1) {
                    if (bfs(i, j, color++)) stop = false;
                }
            }
        }

        if (stop) break;
        ++ans;
    }

    cout << ans;
    return 0;
}
