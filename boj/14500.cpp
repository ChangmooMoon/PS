#include <iostream>
using namespace std;

const int dr[] = {1, 0, -1, 0};
const int dc[] = {0, 1, 0, -1};

int a[501][501];  // 1~1000인 자연수
bool check[501][501];
int n, m, ans = -1;

void go(int r, int c, int sum, int cnt) {
    if (cnt == 4) {
        ans = max(ans, sum);
        return;
    }
    if (r < 0 || c < 0 || r >= n || c >= m) return;
    if (check[r][c]) return;

    check[r][c] = true; // (r,c)로 방문 체크
    for (int i = 0; i < 4; ++i) {
        go(r + dr[i], c + dc[i], sum + a[r][c], cnt + 1);
    }
    check[r][c] = false; // 방문한 자리 또 방문가능
}

void tBlock(int r, int c) {
    if (r + 2 < n) {
        int sum = a[r][c] + a[r + 1][c] + a[r + 2][c];
        if (c + 1 < m) {  // down
            int down = sum + a[r + 1][c + 1];
            ans = max(ans, down);
        }
        if (c - 1 >= 0) {  // up
            int up = sum + a[r + 1][c - 1];
            ans = max(ans, up);
        }
    }

    if (c + 2 < m) {
        int sum = a[r][c] + a[r][c + 1] + a[r][c + 2];
        if (r + 1 < n) {  // right
            int right = sum + a[r + 1][c + 1];
            ans = max(ans, right);
        }
        if (r - 1 >= 0) {  // left
            int left = sum + a[r - 1][c + 1];
            ans = max(ans, left);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;  // 세로 가로
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            go(i, j, 0, 0);
            tBlock(i, j);
        }
    }

    cout << ans;
    return 0;
}
