#include <cstring>
#include <iostream>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n, m;
int a[501][501], d[501][501];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int go(int r, int c) {
    if (r == n && c == m) return 1;
    int &ret = d[r][c];
    if (ret != -1) return ret;

    ret = 0;
    for (int i = 0; i < 4; ++i) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (0 >= nr || 0 >= nc || n < nr || m < nc) continue;
        if (a[r][c] > a[nr][nc]) ret += go(nr, nc);
    }
    return ret;
}

int main() {
    FASTIO;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }
    memset(d, -1, sizeof(d));
    cout << go(1, 1);
    return 0;
}
