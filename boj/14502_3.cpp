#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int n, m, ans;
int a[8][8];  // 0빈칸 1벽 2바이러스
int cpya[8][8];
queue<pii> virus;

int bfs() {
    queue<pii> q = virus;
    while (!q.empty()) {
        int r, c;
        tie(r, c) = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (0 > nr || 0 > nc || n <= nr || m <= nc) continue;
            if (a[nr][nc] == 0) {
                a[nr][nc] = 2;
                q.push({nr, nc});
            }
        }
    }
    int ret = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 0) ++ret;
        }
    }
    return ret;
}

int main() {
    FASTIO;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            if (a[i][j] == 2) virus.push({i, j});
        }
    }
    memcpy(cpya, a, sizeof(a));

    // r1, c1, r2, c2, r3, c3 // 64^3
    for (int r1 = 0; r1 < n; ++r1) {
        for (int c1 = 0; c1 < m; ++c1) {
            if (a[r1][c1] != 0) continue;
            for (int r2 = 0; r2 < n; ++r2) {
                for (int c2 = 0; c2 < m; ++c2) {
                    if (a[r2][c2] != 0) continue;
                    for (int r3 = 0; r3 < n; ++r3) {
                        for (int c3 = 0; c3 < m; ++c3) {
                            if (a[r3][c3] != 0) continue;
                            if (r1 == r2 && c1 == c2) continue;
                            if (r1 == r3 && c1 == c3) continue;
                            if (r2 == r3 && c2 == c3) continue;
                            a[r1][c1] = 1, a[r2][c2] = 1, a[r3][c3] = 1;
                            ans = max(ans, bfs());
                            memcpy(a, cpya, sizeof(a));
                        }
                    }
                }
            }
        }
    }

    cout << ans;
    return 0;
}
