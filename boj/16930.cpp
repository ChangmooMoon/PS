#include <cstring>
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
typedef pair<int, int> pii;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
#define INF 0x3f3f3f3f

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int n, m, k, sr, sc, er, ec;
string a[1001]; // . #
int d[1001][1001];

int bfs() {
    queue<pii> q;
    q.push({sr, sc});
    d[sr][sc] = 0;

    while (!q.empty()) {
        int r, c;
        tie(r, c) = q.front();
        if (r == er && c == ec) return d[r][c];
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nr = r;
            int nc = c;
            for (int j = 0; j < k; ++j) {
                nr += dr[i];
                nc += dc[i];
                if (0 > nr || 0 > nc || n <= nr || m <= nc) break;
                if (a[nr][nc] == '#' || d[nr][nc] < d[r][c] + 1) break;
                if (d[nr][nc] == INF) {
                    q.push({nr, nc});
                    d[nr][nc] = d[r][c] + 1;
                }
            }
        }
    }
    return -1;
}

int main() {
    FASTIO;
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cin >> sr >> sc >> er >> ec;
    --sr, --sc, --er, --ec;
    memset(d, INF, sizeof(d));
    cout << bfs();
    return 0;
}
