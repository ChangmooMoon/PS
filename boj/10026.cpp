#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int n, ans = 0;
string a[101];
bool check[101][101];

void dfs(int x, int y) {
    check[x][y] = true;

    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (0 > nx || 0 > ny || nx >= n || ny >= n) continue;
        if (a[x][y] != a[nx][ny] || check[nx][ny]) continue;

        dfs(nx, ny);
    }
}

void dfsLoop() {
    memset(check, false, sizeof(check));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!check[i][j]) {
                dfs(i, j);
                ans++;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    dfsLoop();
    cout << ans << ' ';

    ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] == 'R') a[i][j] = 'G';
        }
    }

    dfsLoop();
    cout << ans;
    return 0;
}
