#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};
int n;  // n 25
int a[25][25];
int check[25][25];
int ans[626];  // 1~625번 그룹

void dfs(int y, int x, int group) {
    check[y][x] = group;
    for (int i = 0; i < 4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (0 <= ny && ny < n && 0 <= nx && nx < n) {
            if (a[ny][nx] && !check[ny][nx]) {
                dfs(ny, nx, group);
            }
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%1d", &a[i][j]);
        }
    }

    int group = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] && !check[i][j]) {
                group++;
                dfs(i, j, group);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int idx = check[i][j];
            if (idx != 0) {
                ans[idx]++;
            }
        }
    }

    sort(ans, ans + group + 1);
    cout << group << '\n';
    for (int i = 1; i <= group; ++i) {
        cout << ans[i] << '\n';
    }
    return 0;
}
