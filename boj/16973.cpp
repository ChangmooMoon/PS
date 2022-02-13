#include <cstring>
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
typedef pair<int, int> pii;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int n, m, h, w, sr, sc, er, ec;
int a[1001][1001], d[1001][1001], s[1001][1001];  // 부분합

int calcArea(int r1, int c1, int r2, int c2) {
    return s[r2][c2] - s[r1 - 1][c2] - s[r2][c1 - 1] + s[r1 - 1][c1 - 1];
}

int go(int sr, int sc, int er, int ec) {
    queue<pii> q;
    q.push({sr, sc});
    d[sr][sc] = 0;

    while (!q.empty()) {
        int r, c;
        tie(r, c) = q.front();
        if (r == er && c == ec) return d[r][c];
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (1 <= nr && nr + h - 1 <= n && 1 <= nc && nc + w - 1 <= m) {
                if (calcArea(nr, nc, nr + h - 1, nc + w - 1)) continue;
                if (d[nr][nc] != -1) continue;
                q.push({nr, nc});
                d[nr][nc] = d[r][c] + 1;
            }
        }
    }
    return -1;
}

int main() {
    FASTIO;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }
    cin >> h >> w >> sr >> sc >> er >> ec;
    memset(d, -1, sizeof(d));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
        }
    }
    cout << go(sr, sc, er, ec);
    return 0;
}
