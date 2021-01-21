#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};  // 시계방향 8방향
int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};

int w, h;       // 50*50
int a[50][50];  // 바다0, 땅1

void dfs(int x, int y) {
    a[x][y] = 0;
    for (int i = 0; i < 8; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < h && 0 <= ny && ny < w) {
            if (a[nx][ny]) {
                dfs(nx, ny);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while (1) {
        cin >> w >> h;
        if (w == 0 && h == 0) break;

        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                cin >> a[i][j];
            }
        }

        int island = 0;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (a[i][j]) {
                    island++;
                    dfs(i, j);
                }
            }
        }
        cout << island << '\n';
    }

    return 0;
}
