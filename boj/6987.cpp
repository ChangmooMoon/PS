#include <iostream>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int c1[15], c2[15], a[6][3];
// 백트래킹

bool dfs(int cnt) {
    if (cnt == 15) return 1;

    int t1 = c1[cnt], t2 = c2[cnt];
    if (a[t1][0] && a[t2][2]) {
        --a[t1][0], --a[t2][2];
        if (dfs(cnt + 1)) return 1;
        ++a[t1][0], ++a[t2][2];
    }
    if (a[t1][1] && a[t2][1]) {
        --a[t1][1], --a[t2][1];
        if (dfs(cnt + 1)) return 1;
        ++a[t1][1], ++a[t2][1];
    }
    if (a[t1][2] && a[t2][0]) {
        --a[t1][2], --a[t2][0];
        if (dfs(cnt + 1)) return 1;
        ++a[t1][2], ++a[t2][0];
}
    return 0;
}

int main() {
    FASTIO;
    int p = 0;
    for (int i = 0; i < 6; ++i) {
        for (int j = i + 1; j < 6; ++j) {
            c1[p] = i, c2[p++] = j;
        }
    }
    for (int k = 0; k < 4; ++k) {
        int total = 0;
        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 3; ++j) {
                cin >> a[i][j];
                total += a[i][j];
            }
        }
        if (total != 30)
            cout << 0 << ' ';
        else
            cout << dfs(0) << ' ';
    }
    return 0;
}