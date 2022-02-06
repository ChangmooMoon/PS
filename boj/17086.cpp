#include <cstring>
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int dr8[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc8[] = {0, 1, 1, 1, 0, -1, -1, -1};

int n, m;
int a[50][50];
int d[50][50];
queue<pii> q;

int bfs() {
    while (!q.empty()) {
        int r, c;
        tie(r, c) = q.front();
        q.pop();
        for (int i = 0; i < 8; ++i) {
            int nr = r + dr8[i];
            int nc = c + dc8[i];
            if (0 > nr || 0 > nc || n <= nr || m <= nc) continue;
            if (d[nr][nc] != -1) continue;
            q.push({nr, nc});
            d[nr][nc] = d[r][c] + 1;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (ans < d[i][j]) ans = d[i][j];
        }
    }
    return ans;
}

int main() {
    FASTIO;
    cin >> n >> m;
    memset(d, -1, sizeof(d));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            if (a[i][j]) {
                q.push({i, j});
                d[i][j] = 0;
            };
        }
    }

    cout << bfs();
    return 0;
}
