#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int n;
int a[501][501];
int c[501][501];

int go(int x, int y) {  // d[n] = max(d[i-1][j-1], d[i-1][j]) + a[i][j]
    if (x == n)         // 맨 아래에 도달
        return a[x][y];
    if (c[x][y] != -1) {  // 이미 제일 큰 값이 저장되있음
        return c[x][y];
    } else {
        c[x][y] = a[x][y] + max(go(x + 1, y), go(x + 1, y + 1));  // 합이 제일 큰 경우
        return c[x][y];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            cin >> a[i][j];
        }
    }
    memset(c, -1, sizeof(c));

    cout << go(1, 1);
    return 0;
}
