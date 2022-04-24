#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#define INF 0x3f3f3f3f
#define X first
#define Y second
using namespace std;
typedef pair<int, int> pii;

int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

int bfs(vector<vector<int>> &board, pii src, pii dest) {
    queue<pii> q;
    int d[4][4];
    memset(d, -1, sizeof(d));

    q.push(src);
    d[src.X][src.Y] = 0;

    while (!q.empty()) {
        auto &[r, c] = q.front();
        q.pop();

        if (r == dest.X && c == dest.Y) return d[r][c];

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (0 > nr || 0 > nc || 4 <= nr || 4 <= nc) continue;
            if (d[nr][nc] == -1) {
                d[nr][nc] = d[r][c] + 1;
                q.push({nr, nc});
            }

            for (int j = 0; j < 2; ++j) { // ctrl
                if (board[nr][nc]) break;

                int nnr = nr + dr[i];
                int nnc = nc + dc[i];
                if (0 > nnr || 0 > nnc || 4 <= nnr || 4 <= nnc) break;

                nr = nnr;
                nc = nnc;
            }

            if (d[nr][nc] == -1) {
                d[nr][nc] = d[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }

    return -1;
}

int go(vector<vector<int>> &board, pii src) {
    int ret = INF;

    for (int k = 1; k <= 6; ++k) {
        vector<pii> card; // 같은색카드 위치

        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                if (board[i][j] == k) card.push_back({i, j});
            }
        }

        if (card.empty()) continue;

        int ab = bfs(board, src, card[0]) + bfs(board, card[0], card[1]) + 2;
        int ba = bfs(board, src, card[1]) + bfs(board, card[1], card[0]) + 2;
        board[card[0].X][card[0].Y] = board[card[1].X][card[1].Y] = 0;

        int abRecursive = ab + go(board, card[1]);
        int baRecursive = ba + go(board, card[0]);
        ret = min({ret, abRecursive, baRecursive});

        board[card[0].X][card[0].Y] = board[card[1].X][card[1].Y] = k;
    }

    if (ret == INF) return 0;
    return ret;
}

int solution(vector<vector<int>> board, int r, int c) { return go(board, {r, c}); }
