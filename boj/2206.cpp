#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int n, m;
int map[1001][1001];
int dist[1001][1001][2];  // x,y, cnt벽부순횟수

int bfs() {
    queue<tuple<int, int, int>> q;
    q.push({0, 0, 0});
    dist[0][0][0] = 1;

    while (!q.empty()) {
        int x, y, cnt;
        tie(x, y, cnt) = q.front();
        q.pop();
        if (x == n - 1 && y == m - 1) return dist[x][y][cnt];

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (dist[nx][ny][cnt] != 0) continue;

            if (map[nx][ny] == 0) {
                dist[nx][ny][cnt] = dist[x][y][cnt] + 1;
                q.push({nx, ny, cnt});
            }
            if (map[nx][ny] == 1 && cnt == 0) {
                dist[nx][ny][1] = dist[x][y][cnt] + 1;
                q.push({nx, ny, 1});
            }
        }
    }
    return -1;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%1d", &map[i][j]);
        }
    }

    cout << bfs();

    return 0;
}
