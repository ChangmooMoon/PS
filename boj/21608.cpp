#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// 우선순위큐 이용한 우선순위 구현

const int dr[4] = {-1, 1, 0, 0};
const int dc[4] = {0, 0, -1, 1};

struct Pos {
    int r, c, nBlank, nFriend;
    bool operator<(const Pos& other) const {
        if (nFriend == other.nFriend) {
            if (nBlank == other.nBlank) {
                if (r == other.r) return c > other.c;
                return r > other.r;
            }
            return nBlank < other.nBlank;
        }
        return nFriend < other.nFriend;
    }
};

struct Student {
    int sid, prefer[4], r, c;
};

int n, ans = 0;
int board[20][20];
Student student[400];

void arrange() {
    for (int id = 0; id < n * n; ++id) {
        priority_queue<Pos> pq;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j]) continue;

                int nBlank = 0, nFriend = 0;
                for (int d = 0; d < 4; ++d) {
                    int nr = i + dr[d];
                    int nc = j + dc[d];
                    if (0 > nr || 0 > nc || n <= nr || n <= nc) continue;
                    if (board[nr][nc] == 0) {
                        ++nBlank;
                    } else {
                        for (int k = 0; k < 4; ++k) {
                            if (board[nr][nc] == student[id].prefer[k]) {
                                ++nFriend;
                                break;
                            }
                        }
                    }
                }

                pq.push({i, j, nBlank, nFriend});
            }
        }

        if (!pq.empty()) {
            int r = pq.top().r;
            int c = pq.top().c;
            board[r][c] = student[id].sid;
            student[id].r = r;
            student[id].c = c;
        }
    }
}

int calc_score() {
    int ret = 0;
    for (int id = 0; id < n * n; ++id) {
        int r = student[id].r;
        int c = student[id].c;
        int nFriend = 0;
        for (int d = 0; d < 4; ++d) {
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (0 > nr || 0 > nc || n <= nr || n <= nc) continue;
            for (int k = 0; k < 4; ++k) {
                if (board[nr][nc] == student[id].prefer[k]) {
                    ++nFriend;
                    break;
                }
            }
        }

        if (nFriend == 1)
            ret += 1;
        else if (nFriend == 2)
            ret += 10;
        else if (nFriend == 3)
            ret += 100;
        else if (nFriend == 4)
            ret += 1000;
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n * n; ++i) {
        cin >> student[i].sid;
        for (int j = 0; j < 4; ++j) {
            cin >> student[i].prefer[j];
        }
    }

    arrange();
    cout << calc_score();
    return 0;
}
