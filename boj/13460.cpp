#include <iostream>
using namespace std;

// 비트마스크, bfs
const int dr[] = {1, 0, -1, 0};
const int dc[] = {0, 1, 0, -1};

int n, m, ans = -1;
char map[10][10]; // .빈칸 #벽 O구멍 R빨강구슬 B파랑구슬

// 빨간구슬 먼저, 파란구슬 실패, 최소 몇번만에 탈출
void solve(int r1, int c1, int r2, int c2, int cnt) {
    if (cnt > 10) {
        ans = -1;
        return;
    }

    for (int i = 0; i < 4; ++i) {
        int nr1 = r1 + dr[i];
        int nc1 = c1 + dc[i];
        int nr2 = r2 + dr[i];
        int nc2 = c2 + dc[i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    int r1, c1, r2, c2;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> map[i][j];
            if (map[i][j] == 'R') {
                r1 = i;
                c1 = j;
            }
            if (map[i][j] == 'B') {
                r2 = i;
                c2 = j;
            }
        }
    }

    solve(r1, c1, r2, c2, 0);
    cout << ans;
    return 0;
}
