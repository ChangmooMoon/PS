#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <tuple>
using namespace std;
typedef tuple<int, int, int> tiii;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int n, m, sr, sc;
string a[50];
int d[50][50][1 << 6];

int bfs() {
    memset(d, -1, sizeof(d));
    queue<tiii> q;
    q.push({sr, sc, 0});
    d[sr][sc][0] = 0;

    while (!q.empty()) {
        int r, c, k;
        tie(r, c, k) = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            int nk = k;
            if (nr < 0 || nc < 0 || n <= nr || m <= nc) continue;
            if (a[nr][nc] == '#' || d[nr][nc][nk] != -1) continue;
            if ('A' <= a[nr][nc] && a[nr][nc] <= 'F' && !(nk & (1 << (a[nr][nc] - 'A')))) continue;
            if ('a' <= a[nr][nc] && a[nr][nc] <= 'f') nk |= (1 << (a[nr][nc] - 'a'));
            q.push({nr, nc, nk});
            d[nr][nc][nk] = d[r][c][k] + 1;
            if (a[nr][nc] == '1') return d[nr][nc][nk];
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
            if (a[i][j] == '0') sr = i, sc = j;
        }
    }
    cout << bfs();
    return 0;
}
