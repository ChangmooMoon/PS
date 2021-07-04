#include <cstring>
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int r, c;
string a[50];           //.빈칸 *물 X돌 D비버굴 S고슴도치
int waterTime[50][50];  // 물 도달시간
int d[50][50];          // 고슴도치 도달시간
int sr, sc, er, ec;

// 물이 갈수 있는 곳: ., *, S 위치
void waterBfs() {
    queue<pair<int, int>> q;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; j++) {
            if (a[i][j] == '*') q.push({i, j});
        }
    }

    while (!q.empty()) {
        int x, y;
        tie(x, y) = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (0 > nx || 0 > ny || r <= nx || c <= ny) continue;
            if (waterTime[nx][ny] != -1) continue;
            if (a[nx][ny] == 'X' || a[nx][ny] == 'D') continue;

            waterTime[nx][ny] = waterTime[x][y] + 1;
            q.push({nx, ny});
        }
    }
}

void bfs() {
    memset(d, -1, sizeof(d));
    queue<pair<int, int>> q;
    q.push({sr, sc});
    d[sr][sc] = 0;

    while (!q.empty()) {
        int x, y;
        tie(x, y) = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (0 > nx || 0 > ny || r <= nx || c <= ny) continue;
            if (d[nx][ny] != -1 || a[nx][ny] == 'X') continue;
            if (waterTime[nx][ny] != -1 && d[x][y] + 1 >= waterTime[nx][ny]) continue;

            d[nx][ny] = d[x][y] + 1;
            q.push({nx, ny});
        }
    }
}

// 매 분마다 고슴도치 이동, 물 확장
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> r >> c;
    for (int i = 0; i < r; ++i) {
        cin >> a[i];
    }

    memset(waterTime, -1, sizeof(waterTime));
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (a[i][j] == '*') {
                waterTime[i][j] = 0;
            } else if (a[i][j] == 'S') {
                sr = i;
                sc = j;
            } else if (a[i][j] == 'D') {
                er = i;
                ec = j;
            }
        }
    }
    waterBfs();
    bfs();

    d[er][ec] == -1 ? cout << "KAKTUS" : cout << d[er][ec];

    return 0;
}
