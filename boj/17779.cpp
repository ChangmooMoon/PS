#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int n, a[22][22];
int cnt[5], g[22][22];
int ans = -1;

void dfs(int r, int c, int color) {
    g[r][c] = color;
    for (int i = 0; i < 4; ++i) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (1 > nr || 1 > nc || n < nr || n < nc || g[nr][nc]) continue;
        dfs(nr, nc, color);
    }
}

void go(int x, int y, int d1, int d2) {
    memset(cnt, 0, sizeof(cnt));
    memset(g, 0, sizeof(g));
    for (int i = x, j = y; ((i <= x + d1) && (j >= y - d1)); ++i, --j) {
        g[i][j] = 5;
    }
    for (int i = x, j = y; ((i <= x + d2) && (j <= y + d2)); ++i, ++j) {
        g[i][j] = 5;
    }
    for (int i = x + d1, j = y - d1; ((i <= x + d1 + d2) && (j <= y - d1 + d2)); ++i, ++j) {
        g[i][j] = 5;
    }
    for (int i = x + d2, j = y + d2; ((i <= x + d2 + d1) && (j >= y + d2 - d1)); ++i, --j) {
        g[i][j] = 5;
    }

    dfs(x + 1, y, 5);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (g[i - 1][j] == 5 && g[i + 1][j] == 5 && g[i][j - 1] == 5 && g[i][j + 1] == 5) {
                g[i][j] = 5;
            }
        }
    }

    for (int r = 1; r <= n; ++r) {
        for (int c = 1; c <= n; ++c) {
            if (g[r][c] == 5) continue;

            if (r < x + d1 && c <= y)
                g[r][c] = 1;
            else if (r <= x + d2 && y < c)
                g[r][c] = 2;
            else if (x + d1 <= r && c < y - d1 + d2)
                g[r][c] = 3;
            else
                g[r][c] = 4;
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cnt[g[i][j] - 1] += a[i][j];
        }
    }
    sort(cnt, cnt + 5);
    int diff = cnt[4] - cnt[0];
    if (ans == -1 || ans > diff) ans = diff;
}

int main() {
    FASTIO;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int d1 = 1; d1 <= n; ++d1) {
                for (int d2 = 1; d2 <= n; ++d2) {
                    if (i + d1 + d2 <= n) {
                        if (1 <= j - d1) {
                            if (j + d2 <= n) go(i, j, d1, d2);
                        }
                    }
                }
            }
        }
    }

    cout << ans;
    return 0;
}
