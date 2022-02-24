#include <algorithm>
#include <iostream>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

bool a[101][101];
int n, m, k, ans;

int dfs(int r, int c) {
    if (!a[r][c]) return 0;
    if (0 >= r || 0 >= c || n < r || m < c) return 0;
    a[r][c] = 0;
    return 1 + dfs(r - 1, c) + dfs(r + 1, c) + dfs(r, c - 1) + dfs(r, c + 1);
}

int main() {
    FASTIO;
    cin >> n >> m >> k;
    while (k--) {
        int r, c;
        cin >> r >> c;
        a[r][c] = true;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i][j]) ans = max(ans, dfs(i, j));
        }
    }
    cout << ans;
    return 0;
}
