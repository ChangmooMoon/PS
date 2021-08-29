#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

// 백트래킹 표준
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int m, n;
int board[20][20];
int check[26];

int go(int nowr, int nowc, int len) {
    int ret = 0;
    check[board[nowr][nowc]] = 1;

    for (int i = 0; i < 4; ++i) {
        int nr = nowr + dr[i];
        int nc = nowc + dc[i];
        if (0 > nr || 0 > nc || m <= nr || n <= nc) continue;
        if (check[board[nr][nc]]) continue;

        ret = max(ret, go(nr, nc, len + 1));
    }

    check[board[nowr][nowc]] = 0;
    return ret + 1;
}

int main() {
    FASTIO;
    cin >> m >> n;
    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < n; ++j) {
            board[i][j] = s[j] - 'A';
        }
    }

    cout << go(0, 0, 1);
    return 0;
}
