#include <iostream>
#include <queue>

using namespace std;

int dy[]{1, -1, 0, 0};
int dx[]{0, 0, 1, -1};
int n, m;         // 도착지
int d[101][101];  // 거리
int a[101][101];  // 맵

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf("%1d", &a[i][j]);
        }
    }

    queue<pair<int, int>> q;
    q.push({1, 1});
    d[1][1] = 1;
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        if (y == n && x == m) {
            cout << d[y][x];
            break;
        }

        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (1 <= ny && ny <= n && 1 <= nx && nx <= m && !d[ny][nx] && a[ny][nx]) {
                d[ny][nx] = d[y][x] + 1;
                q.push({ny, nx});
            }
        }
    };
    return 0;
}