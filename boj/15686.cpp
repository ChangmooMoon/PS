#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <tuple>
using namespace std;
typedef tuple<int, int, int, int> tiii;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int n, m, sr, sc, r1 = -1, c1, r2, c2;
string a[50];
int d[50][50][4][4];
// d[r][c][dir][gift] // gift: 0, 1, 2, 3

int bfs() {
    memset(d, -1, sizeof(d));
    queue<tiii> q;
    for (int dir = 0; dir < 4; ++dir) {
        q.push({sr, sc, dir, 0});
        d[sr][sc][dir][0] = 0;
    }

    while (!q.empty()) {
        int r, c, dir, gift;
        tie(r, c, dir, gift) = q.front();
        if (gift == 3) {
            return d[r][c][dir][gift];
        }
        q.pop();

        for (int i = 0; i < 4; ++i) {
            if (dir == i) continue;
            int nr = r + dr[i];
            int nc = c + dc[i];
            int ndir = i;
            int ngift = gift;
            if (0 > nr || 0 > nc || n <= nr || m <= nc) continue;
            if (a[nr][nc] == '#') continue;
            if (a[nr][nc] == 'C') {
                if (nr == r1 && nc == c1)
                    ngift |= 1;
                else
                    ngift |= 2;
            }
            if (d[nr][nc][ndir][ngift] != -1) continue;
            q.push({nr, nc, ndir, ngift});
            d[nr][nc][ndir][ngift] = d[r][c][dir][gift] + 1;
        }
    }
    return -1;
}

int main() {
    FASTIO;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 'S') {
                sr = i;
                sc = j;
            }
            if (a[i][j] == 'C') {
                if (r1 == -1) {
                    r1 = i;
                    c1 = j;
                } else {
                    r2 = i;
                    c2 = j;
                }
            }
        }
    }

    cout << bfs();
    return 0;
}
