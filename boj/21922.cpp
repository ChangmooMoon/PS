#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
#define INF 0x3f3f3f3f

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int n, m, a[2001][2001]; // 1, 2, 3, 4, 9 에어컨, 0
vector<pair<int, int>> pos;
bool check[2001][2001][4];

bool isRange(int r, int c) { return 0 <= r && 0 <= c && r < n && c < m; }

void simulate(int sr, int sc) {
    for (int i = 0; i < 4; ++i) {
        check[sr][sc][i] = true;
    }

    for (int d = 0; d < 4; ++d) {
        int r = sr, c = sc, dir = d;
        while (1) {
            int nr = r + dr[dir];
            int nc = c + dc[dir];
            if (!isRange(nr, nc) || check[nr][nc][dir]) break;

            check[nr][nc][dir] = true;
            r = nr, c = nc;
            if (a[nr][nc] == 1) {
                if (dir == 1 || dir == 3) break;
            } else if (a[nr][nc] == 2) {
                if (dir == 0 || dir == 2) break;
            } else if (a[nr][nc] == 3) {
                if (dir == 0)
                    dir = 1;
                else if (dir == 1)
                    dir = 0;
                else if (dir == 2)
                    dir = 3;
                else if (dir == 3)
                    dir = 2;
            } else if (a[nr][nc] == 4) {
                if (dir == 0)
                    dir = 3;
                else if (dir == 3)
                    dir = 0;
                else if (dir == 1)
                    dir = 2;
                else if (dir == 2)
                    dir = 1;
            }
        }
    }
}

int main() {
    FASTIO;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            if (a[i][j] == 9) pos.push_back({i, j});
        }
    }

    for (auto &[r, c] : pos) {
        simulate(r, c);
    }

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < 4; ++k) {
                if (check[i][j][k]) {
                    ++cnt;
                    break;
                }
            }
        }
    }

    cout << cnt;
    return 0;
}
