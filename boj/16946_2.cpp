#include <iostream>
#include <unordered_set>
using namespace std;
#define endl '\n'
// dfs 갯수 카운트

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int n, m;
int a[1001][1001];
int t[1001][1001];
bool check[1001][1001];
int team[1001 * 1001];

int dfs(int r, int c, int clr) {
    t[r][c] = clr;
    check[r][c] = true;

    int ret = 1;
    for (int i = 0; i < 4; ++i) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (0 > nr || 0 > nc || n <= nr || m <= nc) continue;
        if (check[nr][nc] || a[nr][nc]) continue;
        ret += dfs(nr, nc, clr);
    }
    return ret;
}

void grouping() {
    int color = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!a[i][j] && !check[i][j]) {
                team[color] = dfs(i, j, color);
                ++color;
            }
        }
    }
}

int cnt(int r, int c) {
    int ret = 1;
    unordered_set<int> uset;
    for (int i = 0; i < 4; ++i) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (0 > nr || 0 > nc || n <= nr || m <= nc) continue;
        uset.insert(t[nr][nc]);
    }
    for (int i : uset) ret += team[i];
    return ret % 10;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%1d", &a[i][j]);
        }
    }
    grouping();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!a[i][j])
                cout << 0;
            else
                cout << cnt(i, j);
        }
        cout << endl;
    }
    return 0;
}
