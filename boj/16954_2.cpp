#include <cstring>
#include <iostream>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

// dfs식 탐색 재귀

int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1, 0};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1, 0};

char a[8][8];

bool solve(int r, int c) {
    if (a[r][c] == '#') return false;
    if (r == 0) return true;

    for (int d = 0; d < 9; ++d) {
        int nr = r + dr[d];
        int nc = c + dc[d];
        if (0 > nr || 0 > nc || 8 <= nr || 8 <= nc || a[nr][nc] == '#') continue;

        char cpya[8][8];
        memcpy(cpya, a, sizeof(a));
        for (int i = 7; i >= 0; --i) {
            for (int j = 0; j < 8; ++j) {
                if (i == 0)
                    a[i][j] = '.';
                else
                    a[i][j] = a[i - 1][j];
            }
        }
        if (solve(nr, nc)) return true;
        memcpy(a, cpya, sizeof(a));
    }
    return false;
}

int main() {
    FASTIO;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            cin >> a[i][j];
        }
    }
    cout << solve(7, 0);
    return 0;
}
