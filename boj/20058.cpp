#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

int n, q;
int board[64][64];
int tmp[64][64];
bool check[64][64];
bool melt[64][64];

void rotate(int r, int c, int len) {
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            tmp[i][j] = board[r + len - j - 1][c + i];
        }
    }

    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            board[r + i][c + j] = tmp[i][j];
        }
    }
}

void solve(int len) {
    len = 1 << len;
    for (int i = 0; i < n; i += len) {
        for (int j = 0; j < n; j += len) {
            rotate(i, j, len);
        }
    }

    memset(melt, false, sizeof(melt));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] == 0) continue;

            int ice = 0;
            for (int d = 0; d < 4; ++d) {
                int nr = i + dr[d];
                int nc = j + dc[d];
                if (0 > nr || 0 > nc || n <= nr || n <= nc) continue;
                if (board[nr][nc] == 0) continue;
                ++ice;
            }
            if (ice < 3) melt[i][j] = true;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (melt[i][j]) --board[i][j];
        }
    }
}

int dfs(int r, int c) {
    check[r][c] = true;
    int ret = 1;

    for (int i = 0; i < 4; ++i) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (0 > nr || 0 > nc || n <= nr || n <= nc) continue;
        if (check[nr][nc] || board[nr][nc] == 0) continue;
        ret += dfs(nr, nc);
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> q;
    n = 1 << n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
        }
    }

    while (q--) {
        int l;
        cin >> l;
        solve(l);
    }

    int sum = 0, big = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            sum += board[i][j];
            if (board[i][j] != 0 && !check[i][j]) big = max(big, dfs(i, j));
        }
    }

    cout << sum << '\n'
         << big;

    return 0;
}
