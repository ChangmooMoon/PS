#include <iostream>
#include <tuple>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int dr[] = {-1, 1, 0, 0};  // 상하좌우
int dc[] = {0, 0, -1, 1};

int n, m, ans = -1;
char a[10][10];              // . # O R B
int gr, gc, rr, rc, br, bc;  // goal, red, blue

int checkD(int d, int nd) {
    if (d == nd) return false;
    if (d == 0 && nd == 1) return false;
    if (d == 1 && nd == 0) return false;
    if (d == 2 && nd == 3) return false;
    if (d == 3 && nd == 2) return false;
    return true;
}

void move(int& r, int& c, int br, int bc, int d) {
    if (r == -1 && c == -1) return;
    for (int i = 1; i <= 8; ++i) {
        r += dr[d];
        c += dc[d];
        if (r == gr && c == gc) {
            r = -1, c = -1;
            break;
        } else if (a[r][c] == '#' || (r == br && c == bc)) {
            r -= dr[d];
            c -= dc[d];
            break;
        }
    }
}

tuple<int, int, int, int> simulation(int r1, int c1, int r2, int c2, int d) {
    // 1red, 2blue
    // 0. goal에 들어감 gr, gc
    // 1. 벽에 박음 a[i][j] = '.'
    // 2. red가 blue에 박음, blue가 red에 박음 red -> blue -> red -> blue
    move(r1, c1, r2, c2, d);
    move(r2, c2, r1, c1, d);
    move(r1, c1, r2, c2, d);
    move(r2, c2, r1, c1, d);
    return {r1, c1, r2, c2};
}

void go(int cnt, int d, int r1, int c1, int r2, int c2) {  // 이전방향d, red, blue
    if (cnt > 10) return;
    if (r2 == -1 && c2 == -1) return;
    if (r1 == -1 && c1 == -1) {
        if (ans == -1 || ans > cnt) {
            ans = cnt;
        }
        return;
    }

    for (int i = 0; i < 4; ++i) {
        if (!checkD(d, i)) continue;
        int nr1, nc1, nr2, nc2;
        tie(nr1, nc1, nr2, nc2) = simulation(r1, c1, r2, c2, i);
        if (r1 == nr1 && c1 == nc1 && r2 == nr2 && c2 == nc2) continue;
        go(cnt + 1, i, nr1, nc1, nr2, nc2);
    }
}

int main() {
    FASTIO;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            if (a[i][j] == 'O') {
                gr = i;
                gc = j;
            } else if (a[i][j] == 'R') {
                rr = i;
                rc = j;
            } else if (a[i][j] == 'B') {
                br = i;
                bc = j;
            }
        }
    }

    go(0, -1, rr, rc, br, bc);
    cout << ans;
    return 0;
}
