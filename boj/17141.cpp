#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int n, m;
int a[50][50];  // 0빈칸 1벽 2바이러스가능칸
vector<pii> vpos;

int bfs(vector<int>& v) {
    int d[50][50];
    memset(d, -1, sizeof(d));

    queue<pii> q;
    for (int i = 0; i < vpos.size(); ++i) {
        if (v[i]) {
            int r, c;
            tie(r, c) = vpos[i];
            q.push({r, c});
            d[r][c] = 0;
        }
    }

    while (!q.empty()) {
        int r, c;
        tie(r, c) = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (0 > nr || 0 > nc || n <= nr || n <= nc) continue;
            if (d[nr][nc] != -1 || a[nr][nc] == 1) continue;

            q.push({nr, nc});
            d[nr][nc] = d[r][c] + 1;
        }
    }

    int ans = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] != 1 && d[i][j] == -1) return -1;
            if (ans == -1 || ans < d[i][j]) ans = d[i][j];
        }
    }

    return ans;
}

int solve() {  // C(10, m)
    vector<int> v(vpos.size() - m);
    for (int i = 0; i < m; ++i) {
        v.push_back(1);
    }

    int ans = -1;
    do {
        int res = bfs(v);
        if (res == -1) continue;
        if (ans == -1 || ans > res) ans = res;
    } while (next_permutation(v.begin(), v.end()));
    return ans;
}

int main() {
    FASTIO;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            if (a[i][j] == 2) vpos.push_back({i, j});
        }
    }

    cout << solve();
    return 0;
}
