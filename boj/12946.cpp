#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int dr[6] = {-1, -1, 0, 1, 1, 0};
int dc[6] = {0, 1, 1, 0, -1, -1};

int n, ans;
char a[50][50];  // -, X
int color[50][50];

void dfs(int r, int c, int group) {
    color[r][c] = group;
    ans = max(ans, 1);

    for (int i = 0; i < 6; ++i) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (0 > nr || 0 > nc || n <= nr || n <= nc) continue;
        if (a[nr][nc] != 'X') continue;
        if (color[nr][nc] == -1) {
            dfs(nr, nc, 1 - group);
        }
        ans = max(ans, 2);
        if (color[nr][nc] == group) {
            ans = 3;
            return;
        }
    }
}

int main() {
    FASTIO;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    memset(color, -1, sizeof(color));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] == 'X' && color[i][j] == -1) dfs(i, j, 0);
        }
    }

    cout << ans;
    return 0;
}
