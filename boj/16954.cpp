#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

const int dx[9] = {1, 1, 1, 0, -1, -1, -1, 0, 0};
const int dy[9] = {-1, 0, 1, 1, 1, 0, -1, -1, 0};

string a[8];
bool visit[8][8][9];  // 0~8초 까지 카운트

bool bfs() {
    queue<tuple<int, int, int>> q;  // r,c,t
    visit[7][0][0] = true;          // 시작
    q.push({7, 0, 0});

    while (!q.empty()) {
        int x, y, t;
        tie(x, y, t) = q.front();
        q.pop();
        if ((x == 0 && y == 7) || t == 8) return true;

        for (int i = 0; i < 9; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nt = t + 1;

            if (0 > nx || 0 > ny || nx >= 8 || ny >= 8) continue;
            if (nx - t >= 0 && a[nx - t][ny] == '#') continue;
            if (nx - t - 1 >= 0 && a[nx - t - 1][ny] == '#') continue;
            if (!visit[nx][ny][nt]) {
                visit[nx][ny][nt] = true;
                q.push({nx, ny, nt});
            }
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int i = 0; i < 8; ++i) {
        cin >> a[i];
    }

    if (bfs())
        cout << 1;
    else
        cout << 0;

    return 0;
}
