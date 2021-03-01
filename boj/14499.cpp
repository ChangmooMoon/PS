#include <cstring>
#include <iostream>

using namespace std;

int dx[] = {0, 0, -1, 1};  //동서북남
int dy[] = {1, -1, 0, 0};
int dice[6];

int n, m, x, y, k;  // 세로20, 가로20, x19, y19, 명령수1000
int a[20][20];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> x >> y >> k;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    while (k--) {
        int order;
        cin >> order;
        int nx = x + dx[order - 1];
        int ny = y + dy[order - 1];
        if (0 > nx || n <= nx || 0 > ny || m <= ny) continue;
        if (order == 1) {  // 동
            // 1-4, 3-1, 6-3, 4-6
            int tmp = dice[0];
            dice[0] = dice[4];
            dice[4] = dice[2];
            dice[2] = dice[5];
            dice[5] = tmp;
        } else if (order == 2) {  // 서
            // 1-3,3-6,6-4,4-1
            int tmp = dice[0];
            dice[0] = dice[5];
            dice[5] = dice[2];
            dice[2] = dice[4];
            dice[4] = tmp;
        } else if (order == 3) {  // 북
            // 5-6, 6-2, 2-1, 1-5
            int tmp = dice[1];
            dice[1] = dice[2];
            dice[2] = dice[3];
            dice[3] = dice[0];
            dice[0] = tmp;
        } else {  // 남
            // 5-1, 1-2, 2-6, 6-5
            int tmp = dice[1];
            dice[1] = dice[0];
            dice[0] = dice[3];
            dice[3] = dice[2];
            dice[2] = tmp;
        }
        x = nx;
        y = ny;
        if (a[x][y] == 0) {
            a[x][y] = dice[2];
        } else {
            dice[2] = a[x][y];
            a[x][y] = 0;
        }

        cout << dice[0] << '\n';
    }

    return 0;
}
