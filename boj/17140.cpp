#include <cstring>
#include <iostream>
#include <queue>
#define pii pair<int, int>
using namespace std;

int r, c, k, ans = -1;
int row = 3, col = 3;  // 행, 열
int board[101][101];
int cnt[101];  // 출현 횟수

int solve() {
    int time = 0;
    while (time <= 100) {
        if (board[r][c] == k) return time;

        if (row >= col) {  // R연산 행 정렬
            for (int i = 1; i <= row; ++i) {
                priority_queue<pii> pq;
                memset(cnt, 0, sizeof(cnt));

                for (int j = 1; j <= col; ++j) {
                    if (board[i][j]) {
                        ++cnt[board[i][j]];
                        board[i][j] = 0;
                    }
                }
                // 1 2 1 -> 1:2, 2:1 -> 21 12
                // 2 1 3 -> 1:1 2:1 3:1 -> 11 21 31
                // 3 3 3 -> 3:3 -> 33
                for (int j = 1; j <= 100; ++j) {         // 횟수 적은 순, 숫자 작은 순
                    if (cnt[j]) pq.push({-cnt[j], -j});  // 최소힙 (횟수, 숫자)
                    // j: 1 cnt[j]: 2
                    // j: 2 cnt[j]: 1
                }

                int size = pq.size() * 2;
                col = max(col, size);
                for (int j = 1; j <= size; j += 2) {
                    const auto& [times, num] = pq.top();

                    board[i][j] = -num;
                    board[i][j + 1] = -times;
                    pq.pop();
                }
            }
        } else {  // C연산 열 정렬
            for (int i = 1; i <= col; ++i) {
                priority_queue<pii> pq;
                memset(cnt, 0, sizeof(cnt));

                for (int j = 1; j <= row; ++j) {
                    if (board[j][i]) {
                        ++cnt[board[j][i]];
                        board[j][i] = 0;
                    }
                }

                for (int j = 1; j <= 100; ++j) {
                    if (cnt[j]) pq.push({-cnt[j], -j});
                }

                int size = pq.size() * 2;
                row = max(row, size);
                for (int j = 1; j <= size; j += 2) {
                    const auto& [times, num] = pq.top();
                    board[j][i] = -num;
                    board[j + 1][i] = -times;
                    pq.pop();
                }
            }
        }

        ++time;
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> r >> c >> k;
    for (int i = 1; i <= 3; ++i) {
        for (int j = 1; j <= 3; ++j) {
            cin >> board[i][j];
        }
    }

    cout << solve();
    return 0;
}
