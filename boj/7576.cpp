#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int m, n;           // m,n 1000*1000 = 1000000
int a[1000][1000];  // -1없음 0안익음 1익음
int d[1000][1000];  // -1방문안함 0+ 방문한 시간

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> m >> n;
    memset(d, -1, sizeof(d));

    queue<pair<int, int>> q;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            if (a[i][j] == 1) {
                q.push({i, j});  // 시작지점
                d[i][j] = 0;
            }
        }
    }

    while (!q.empty()) {
        int x = q.front().first;   // 3
        int y = q.front().second;  // 5
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (a[nx][ny] == 0 && d[nx][ny] == -1) {  // 사과 안익음, 방문 안함
                    a[nx][ny] = 1;                        // 사과 익음
                    d[nx][ny] = d[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }

    int duration = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            duration = max(duration, d[i][j]);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 0 && d[i][j] == -1) {
                duration = -1;
            }
        }
    }
    cout << duration;
    return 0;
}
