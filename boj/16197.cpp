#include <iostream>
#include <vector>
using namespace std;
#define INF 0x3f3f3f3f

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int r, c, ans = INF;
char a[20][20];   // o . #
vector<int> pos;  // r1, c1, r2, c2

bool isAlive(int nr, int nc) {
    if (0 > nr || 0 > nc || nr >= r || nc >= c) return false;
    return true;
}

void go(int cnt, int r1, int c1, int r2, int c2) {
    if (cnt > 10) return;
    if (!isAlive(r1, c1) && !isAlive(r2, c2)) return;
    if ((!isAlive(r1, c1) && isAlive(r2, c2)) || (isAlive(r1, c1) && !isAlive(r2, c2))) {
        if (ans > cnt) ans = cnt;
        return;
    }

    for (int i = 0; i < 4; ++i) {
        int nr1 = r1 + dr[i];
        int nc1 = c1 + dc[i];
        int nr2 = r2 + dr[i];
        int nc2 = c2 + dc[i];
        if (a[nr1][nc1] == '#') {
            nr1 = r1;
            nc1 = c1;
        }
        if (a[nr2][nc2] == '#') {
            nr2 = r2;
            nc2 = c2;
        }
        go(cnt + 1, nr1, nc1, nr2, nc2);
    }
}

int main() {
    cin >> r >> c;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> a[i][j];
            if (a[i][j] == 'o') {
                pos.push_back(i);
                pos.push_back(j);
            }
        }
    }

    go(0, pos[0], pos[1], pos[2], pos[3]);
    if (ans != INF) {
        cout << ans;
    } else
        cout << -1;
    return 0;
}
