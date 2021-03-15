#include <iostream>
using namespace std;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
int n, m;
char a[50][50];
bool visit[50][50];

bool check(int x, int y, int oldx, int oldy, char color) {
    if (visit[x][y]) return true;

    visit[x][y] = true;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (0 > nx || nx >= n || 0 > ny || ny >= m) continue;
        if (nx == oldx && ny == oldy) continue;
        if (a[nx][ny] != color) continue;
        if (check(nx, ny, x, y, color)) return true;
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (visit[i][j]) continue;
            if (check(i, j, -1, -1, a[i][j])) {
                cout << "Yes";
                return 0;
            }
        }
    }

    cout << "No";
    return 0;
}
