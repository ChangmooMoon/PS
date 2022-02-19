#include <cstring>
#include <iostream>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int n, m, t;
int a[51][51], acpy[51][51];
int sr = -1, sc;  // 청정기위치

bool checkRange(int r, int c) {
    if (0 > r || 0 > c || n <= r || m <= c) return false;
    if ((r == sr || r == sr + 1) && c == sc) return false;
    return true;
}

void dust() {
    memset(acpy, 0, sizeof(acpy));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] <= 0) continue;
            int spread = a[i][j] / 5;
            for (int d = 0; d < 4; ++d) {
                int nr = i + dr[d];
                int nc = j + dc[d];
                if (checkRange(nr, nc)) {
                    acpy[nr][nc] += spread;
                    a[i][j] -= spread;
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            a[i][j] += acpy[i][j];
        }
    }
}

void cleaner() {
    for (int i = sr - 1; i >= 0; --i) {
        a[i + 1][0] = a[i][0];
    }
    for (int i = sr + 2; i < n; ++i) {
        a[i - 1][0] = a[i][0];
    }
    for (int i = 1; i < m; ++i) {
        a[0][i - 1] = a[0][i];
        a[n - 1][i - 1] = a[n - 1][i];
    }
    for (int i = 1; i <= sr; ++i) {
        a[i - 1][m - 1] = a[i][m - 1];
    }
    for (int i = n - 2; i >= sr; --i) {
        a[i + 1][m - 1] = a[i][m - 1];
    }
    for (int i = m - 2; i >= 1; --i) {
        a[sr][i + 1] = a[sr][i];
        a[sr + 1][i + 1] = a[sr + 1][i];
    }
    a[sr][1] = a[sr + 1][1] = 0;
    a[sr][sc] = a[sr + 1][sc] = -1;
}

int main() {
    FASTIO;
    cin >> n >> m >> t;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            if (sr == -1 && a[i][j] == -1) {
                sr = i;
                sc = j;
            }
        }
    }

    while (t--) {
        dust();
        cleaner();
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ans += a[i][j];
        }
    }
    cout << ans + 2 << endl;
    return 0;
}
