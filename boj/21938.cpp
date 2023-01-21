#include <bits/stdc++.h>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int N, M, a[1000][3000], a2[1000][1000], d[1000][1000], T;

void dfs(int r, int c, int g) {
    d[r][c] = g;
    for (int i = 0; i < 4; ++i) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (0 > nr || 0 > nc || N <= nr || M <= nc) continue;
        if (!a2[nr][nc] or d[nr][nc] != -1) continue;
        dfs(nr, nc, g);
    }
}

int main() {
    FASTIO;
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 3 * M; ++j) {
            cin >> a[i][j];
        }
    }
    cin >> T;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            int e1 = a[i][3 * j];
            int e2 = a[i][3 * j + 1];
            int e3 = a[i][3 * j + 2];
            if (e1 + e2 + e3 >= T * 3) a2[i][j] = 1;
        }
    }
    memset(d, -1, sizeof(d));

    int group = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (a2[i][j] == 1 && d[i][j] == -1) dfs(i, j, ++group);
        }
    }

    cout << group;
    return 0;
}
