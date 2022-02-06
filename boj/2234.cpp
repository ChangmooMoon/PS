#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int dr[] = {0, -1, 0, 1};  // 서북동남
int dc[] = {-1, 0, 1, 0};

int m, n;
int a[50][50];
int d[50][50];
vector<int> gsize;  // 1~x팀

int dfs(int r, int c, int color) {
    d[r][c] = color;
    int ret = 1;
    for (int i = 0; i < 4; ++i) {
        if (!(a[r][c] & (1 << i))) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (d[nr][nc] == -1) {
                ret += dfs(nr, nc, color);
            }
        }
    }
    return ret;
}

int solve() {
    int ans = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < 4; ++k) {
                if (!(a[i][j] & (1 << k))) continue;  // 벽이 없으면 안됨
                int nr = i + dr[k];
                int nc = j + dc[k];
                if (0 > nr || 0 > nc || n <= nr || m <= nc) continue;
                if (d[nr][nc] == d[i][j]) continue;

                int ret = gsize[d[i][j] - 1] + gsize[d[nr][nc] - 1];
                ans = max(ans, ret);
            }
        }
    }

    return ans;
}

int main() {
    FASTIO;
    cin >> m >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    memset(d, -1, sizeof(d));
    int g = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (d[i][j] == -1) {
                int res = dfs(i, j, ++g);
                gsize.push_back(res);
            }
        }
    }
    cout << gsize.size() << endl
         << *max_element(gsize.begin(), gsize.end()) << endl
         << solve() << endl;

    return 0;
}
