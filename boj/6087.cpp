#include <cstring>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int m, n, sx, sy, ex, ey;
string a[100];
int dist[100][100];  // 선분 갯수
vector<pair<int, int>> loc;

void bfs() {
    memset(dist, -1, sizeof(dist));
    tie(sx, sy) = loc[0];
    tie(ex, ey) = loc[1];

    queue<pair<int, int>> q;
    q.push({sx, sy});
    dist[sx][sy] = 0;

    while (!q.empty()) {
        int x, y;
        tie(x, y) = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            while (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (a[nx][ny] == '*') break;
                if (dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
                nx += dx[i];
                ny += dy[i];
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> m >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 'C') {
                loc.push_back({i, j});
            };
        }
    }

    bfs();
    cout << dist[ex][ey] - 1;

    return 0;
}
