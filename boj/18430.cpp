#include <iostream>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n, m, ans = 0;
int a[5][5];
bool check[5][5];

void go(int r, int c, int sum) {
    if (c == m) {
        c = 0;
        ++r;
    }
    if (r == n) {
        ans = max(sum, ans);
        return;
    }

    if (!check[r][c]) { // rc-오른쪽-아래, rc-아래-왼쪽, rc-아래-오른쪽, 아래-rc-오른쪽
        check[r][c] = true;
        if (c + 1 < m && r + 1 < n && !check[r][c + 1] && !check[r + 1][c + 1]) {
            check[r][c + 1] = true;
            check[r + 1][c + 1] = true;
            go(r, c + 1, sum + a[r][c] + 2 * a[r][c + 1] + a[r + 1][c + 1]);
            check[r][c + 1] = false;
            check[r + 1][c + 1] = false;
        }
        if (r + 1 < n && c - 1 >= 0 && !check[r + 1][c] && !check[r + 1][c - 1]) {
            check[r + 1][c] = true;
            check[r + 1][c - 1] = true;
            go(r, c + 1, sum + a[r][c] + 2 * a[r + 1][c] + a[r + 1][c - 1]);
            check[r + 1][c] = false;
            check[r + 1][c - 1] = false;
        }
        if (r + 1 < n && c + 1 < m && !check[r + 1][c] && !check[r + 1][c + 1]) {
            check[r + 1][c] = true;
            check[r + 1][c + 1] = true;
            go(r, c + 1, sum + a[r][c] + 2 * a[r + 1][c] + a[r + 1][c + 1]);
            check[r + 1][c] = false;
            check[r + 1][c + 1] = false;
        }
        if (r + 1 < n && c + 1 < m && !check[r + 1][c] && !check[r][c + 1]) {
            check[r + 1][c] = true;
            check[r][c + 1] = true;
            go(r, c + 1, sum + 2 * a[r][c] + a[r + 1][c] + a[r][c + 1]);
            check[r + 1][c] = false;
            check[r][c + 1] = false;
        }
        check[r][c] = false;
    }
    go(r, c + 1, sum);
}

int main() {
    FASTIO;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    go(0, 0, 0);
    cout << ans;
    return 0;
}
