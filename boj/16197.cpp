#include <iostream>
#include <vector>
#define pii pair<int, int>
using namespace std;

const int dr[] = {1, 0, -1, 0};
const int dc[] = {0, 1, 0, -1};

int n, m;        // 세로 가로 20
char a[20][20];  // o동전 .빈칸 #벽

// 11번이상이면 -1출력, 동전 하나만 떨어뜨리는 최소횟수
// 버튼 상하좌우 4^10 = 2^20 = 100만

int go(int cnt, int r1, int c1, int r2, int c2) {
    if (cnt == 11) return -1;

    bool fall1 = false, fall2 = false;
    if (r1 < 0 || r1 >= n || c1 < 0 || c1 >= m) fall1 = true;
    if (r2 < 0 || r2 >= n || c2 < 0 || c2 >= m) fall2 = true;
    if (fall1 && fall2) return -1;
    if (fall1 || fall2) return cnt;

    int ans = -1;
    for (int i = 0; i < 4; ++i) {
        int nr1 = r1 + dr[i];
        int nc1 = c1 + dc[i];
        int nr2 = r2 + dr[i];
        int nc2 = c2 + dc[i];

        // 벽이면 이동 안함
        if (0 <= nr1 && nr1 < n && 0 <= nc1 && nc1 < m && a[nr1][nc1] == '#') {
            nr1 = r1;
            nc1 = c1;
        }
        if (0 <= nr2 && nr2 < n && 0 <= nc2 && nc2 < m && a[nr2][nc2] == '#') {
            nr2 = r2;
            nc2 = c2;
        }

        int next = go(cnt + 1, nr1, nc1, nr2, nc2);
        if (next == -1) continue;
        if (ans == -1 || ans > next) ans = next;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    vector<pii> coinPos;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            if (a[i][j] == 'o') {
                coinPos.push_back({i, j});
            }
        }
    }
    auto& [r1, c1] = coinPos[0];
    auto& [r2, c2] = coinPos[1];
    cout << go(0, r1, c1, r2, c2);
    return 0;
}
