#include <cstring>
#include <iostream>
#include <vector>
#define pii pair<int, int>
using namespace std;

const int dr[] = {0, 0, -1, -1, -1, 0, 1, 1, 1};  // 0, ←, ↖, ↑, ↗, →, ↘, ↓, ↙
const int dc[] = {0, -1, -1, 0, 1, 1, 1, 0, -1};  // 0  1  2  3  4  5  6  7  8

int board[50][50];
bool erased[50][50];
int n, m, total;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
        }
    }

    vector<pii> cloud = {{n - 1, 0}, {n - 1, 1}, {n - 2, 0}, {n - 2, 1}};
    vector<pii> erasedList;
    while (m--) {
        erasedList.clear();
        memset(erased, false, sizeof(erased));

        int d, s;  // 방향, 거리
        cin >> d >> s;

        // 1. 구름 이동 2. 물 1 증가
        for (pii& axis : cloud) {
            int r = axis.first;
            int c = axis.second;
            int nr = ((r + dr[d] * s) % n + n) % n;
            int nc = ((c + dc[d] * s) % n + n) % n;

            ++board[nr][nc];
            erased[nr][nc] = true;
            erasedList.push_back({nr, nc});
        }

        // 3. 구름 사라짐
        cloud.clear();

        // 4. 물복사 마법
        for (pii& axis : erasedList) {
            int water = 0;
            int r = axis.first;
            int c = axis.second;

            for (int d = 2; d <= 8; d += 2) {
                int nr = r + dr[d];
                int nc = c + dc[d];
                if (0 > nr || 0 > nc || nr >= n || nc >= n) continue;
                if (board[nr][nc] == 0) continue;

                ++water;
            }
            board[r][c] += water;
        }

        // 5. 물 2 이상이면 구름 생기고 -2
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] >= 2 && !erased[i][j]) {
                    cloud.push_back({i, j});
                    board[i][j] -= 2;
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            total += board[i][j];
        }
    }

    cout << total;
    return 0;
}
