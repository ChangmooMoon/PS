#include <iostream>
#include <tuple>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, 1, -1};

struct Shark {
    int s, d, z;
};

int n, m, k;
Shark a[101][101], acpy[101][101];

int fishing(int col) {
    for (int i = 0; i < n; ++i) {
        if (a[i][col].z > 0) {
            int ret = a[i][col].z;
            a[i][col].z = 0;
            return ret;
        }
    }
    return 0;
}

tuple<int, int, int> getPos(int r, int c, int speed, int dir) {
    for (int k = 0; k < speed; ++k) {
        // 상하오왼
        if (dir == 0) {
            if (r == 0) {
                r = 1;
                dir = 1;
            } else {
                --r;
            }
        } else if (dir == 1) {
            if (r == n - 1) {
                r = n - 2;
                dir = 0;
            } else {
                ++r;
            }
        } else if (dir == 2) {
            if (c == m - 1) {
                c = m - 2;
                dir = 3;
            } else {
                ++c;
            }
        } else if (dir == 3) { // dir == 3
            if (c == 0) {
                c = 1;
                dir = 2;
            } else {
                --c;
            }
        }
    }
    return {r, c, dir};
};

void move() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j].z == 0)
                continue;

            Shark sh = a[i][j];
            int nr, nc, nd;
            tie(nr, nc, nd) = getPos(i, j, sh.s, sh.d);
            if (acpy[nr][nc].z == 0 || acpy[nr][nc].z < sh.z) {
                acpy[nr][nc] = {sh.s, nd, sh.z}; // s d z
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            a[i][j] = acpy[i][j];
            acpy[i][j].z = 0;
        }
    }
}

int main() {
    FASTIO;
    cin >> n >> m >> k;
    while (k--) {
        int r, c, s, d, z; // r,c, speed, dir, size
        cin >> r >> c >> s >> d >> z;
        --r, --c, --d;
        if (d == 0 || d == 1)
            s %= 2 * n - 2;
        else
            s %= 2 * m - 2;

        a[r][c] = {s, d, z};
    }

    int ans = 0;
    for (int j = 0; j < m; ++j) {
        ans += fishing(j);
        move();
    }
    cout << ans;
    return 0;
}
