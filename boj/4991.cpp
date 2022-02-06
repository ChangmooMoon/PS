#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <tuple>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
#define INF 0x3f3f3f3f

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

string a[20];  // . * x o
int m, n;
int robotr, robotc;
vector<pii> dust;
int d[11][11];

int bfs(int sr, int sc, int er, int ec) {
    int dist[20][20];
    memset(dist, -1, sizeof(dist));
    queue<pii> q;
    q.push({sr, sc});
    dist[sr][sc] = 0;

    while (!q.empty() && dist[er][ec] == -1) {
        int r, c;
        tie(r, c) = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (0 > nr || 0 > nc || n <= nr || m <= nc) continue;
            if (a[nr][nc] == 'x' || dist[nr][nc] != -1) continue;
            q.push({nr, nc});
            dist[nr][nc] = dist[r][c] + 1;
        }
    }

    return dist[er][ec];
}

bool calcDist() {
    for (int i = 0; i < dust.size(); ++i) {
        for (int j = i + 1; j < dust.size(); ++j) {
            int sr, sc, er, ec;
            tie(sr, sc) = dust[i], tie(er, ec) = dust[j];
            d[i][j] = bfs(sr, sc, er, ec);
            if (d[i][j] == -1) return false;
            d[j][i] = d[i][j];
        }
    }
    return true;
}

int solve() {
    vector<int> v;  // 1,2,3
    v.push_back(0);
    for (int i = 1; i < dust.size(); ++i) {
        v.push_back(i);
    }

    int ret = INF;
    do {
        int move = 0;
        for (int i = 1; i < dust.size(); ++i) {
            move += d[v[i - 1]][v[i]];
        }
        ret = min(ret, move);
    } while (next_permutation(v.begin() + 1, v.end()));

    return ret;
}

int main() {
    FASTIO;
    while (1) {
        cin >> m >> n;
        if (m == 0 && n == 0) break;
        dust.clear();
        memset(d, -1, sizeof(d));
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            for (int j = 0; j < m; ++j) {
                if (a[i][j] == 'o') {
                    robotr = i;
                    robotc = j;
                    a[i][j] = '.';
                } else if (a[i][j] == '*') {
                    dust.push_back({i, j});
                }
            }
        }

        dust.push_back({robotr, robotc});
        swap(dust[0], *dust.rbegin());
        sort(dust.begin() + 1, dust.end());
        if (!calcDist()) {
            cout << -1 << endl;
            continue;
        }

        cout << solve() << endl;
    }

    return 0;
}
