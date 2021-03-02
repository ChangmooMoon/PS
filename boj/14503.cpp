#include <iostream>
using namespace std;

int dr[] = {-1, 0, 1, 0};  // 북동남서
int dc[] = {0, 1, 0, -1};

int n, m;
int r, c, d;    // (r,c), 0123
int a[50][50];  // 빈칸 0, 벽 1, 청소2

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    cin >> r >> c >> d;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    while (1) {
        if (!a[r][c]) a[r][c] = 2;
        if (a[r + 1][c] && a[r - 1][c] && a[r][c + 1] && !a[r][c - 1]) {
            int nr = r - dr[d];
            int nc = c - dc[d];  // 후진
            if (a[nr][nc] == 1)
                break;
            else {
                r = nr;
                c = nc;
            }
        } else {
            d = (d + 3) % 4;
            int nr = r + dr[d];
            int nc = c + dc[d];  // 왼쪽 탐색
            if (!a[nr][nc]) {
                r = nr;
                c = nc;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 2) ans++;
        }
    }

    cout << ans;
    return 0;
}
