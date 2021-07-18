#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#define pii pair<int, int>
using namespace std;

const int dr[] = {0, 0, 1, -1};
const int dc[] = {1, -1, 0, 0};

struct Group {
    int size, rainbow, sr, sc;
};

int n, m, score;
int board[20][20];  // -2빈칸 -1검은색 0무지개 1,2,3,4,5
int check[20][20];
vector<Group> groupList;

void findBlockGroup() {
    queue<pii> q;  // 그룹 시작점

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int x = 0; x < n; x++) {
                for (int y = 0; y < n; y++) {
                    if (board[x][y] == 0) check[x][y] = false;
                }
            }
            if (board[i][j] <= 0 || check[i][j]) continue;

            q.push({i, j});
            check[i][j] = true;
            int size = 1, rainbow = 0;

            while (!q.empty()) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if (0 > nr || 0 > nc || n <= nr || n <= nc) continue;
                    if ((board[nr][nc] != 0 && board[nr][nc] != board[i][j]) || check[nr][nc]) continue;

                    if (board[nr][nc] == 0) ++rainbow;
                    ++size;
                    q.push({nr, nc});
                    check[nr][nc] = true;
                }
            }

            if (size >= 2) groupList.push_back({size, rainbow, i, j});
        }
    }
}

void eraseBlock() {
    sort(groupList.begin(), groupList.end(), [](Group& a, Group& b) {
        if (a.size == b.size) {
            if (a.rainbow == b.rainbow) {
                if (a.sr == b.sr) return a.sc > b.sc;
                return a.sr > b.sr;
            }
            return a.rainbow > b.rainbow;
        }
        return a.size > b.size;
    });
    score += groupList[0].size * groupList[0].size;

    queue<pii> q;
    vector<pii> eraseList;
    int sr = groupList[0].sr;
    int sc = groupList[0].sc;

    q.push({sr, sc});
    check[sr][sc] = true;
    eraseList.push_back({sr, sc});

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (0 > nr || 0 > nc || n <= nr || n <= nc) continue;
            if ((board[nr][nc] != 0 && board[nr][nc] != board[sr][sc]) || check[nr][nc]) continue;

            check[nr][nc] = true;
            q.push({nr, nc});
            eraseList.push_back({nr, nc});
        }
    }

    for (pii& pos : eraseList) {
        int r = pos.first;
        int c = pos.second;
        board[r][c] = -2;
    }
}

void gravity() {
    for (int i = 0; i < n; i++) {
        queue<int> block;
        queue<int> blackBlock;

        for (int j = n - 1; j >= 0; j--) {
            if (board[j][i] >= -1) block.push(board[j][i]);
            if (board[j][i] == -1) blackBlock.push(j);
        }
        if (block.empty()) continue;

        for (int j = n - 1; j >= 0; j--) board[j][i] = -2;
        for (int j = n - 1; j >= 0; j--) {
            if (block.empty()) break;

            int num = block.front();
            block.pop();
            if (num == -1) {
                int blackR = blackBlock.front();
                blackBlock.pop();
                board[blackR][i] = -1;
                j = blackR;
            } else
                board[j][i] = num;
        }
    }
}

void rotate() {
    int tmp[20][20];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            tmp[i][j] = board[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board[i][j] = tmp[j][n - 1 - i];
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
        }
    }

    while (1) {
        groupList.clear();
        memset(check, 0, sizeof(check));

        findBlockGroup();
        if (groupList.empty()) break;

        memset(check, 0, sizeof(check));
        eraseBlock();

        gravity();
        rotate();
        gravity();
    }

    cout << score;
    return 0;
}
