#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int safe = 0;

int n, m;     // 3~8;
int a[8][8];  // 0빈칸 1벽 2바이러스
int check[8][8];
int backupA[8][8];
vector<pair<int, int>> wallList;  // wall 넣을 후보
vector<int> wallIdx;
int cnt = 0;

void dfs(int x, int y) {
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < n && 0 <= ny && ny < m)
            if (a[nx][ny] == 0) {
                a[nx][ny] = 2;
                dfs(nx, ny);
            }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            if (a[i][j] == 0)
                wallList.push_back({i, j});
        }
    }

    for (int i = 0; i < wallList.size() - 3; ++i)
        wallIdx.push_back(0);
    for (int i = 0; i < 3; ++i)
        wallIdx.push_back(1);
    memcpy(backupA, a, sizeof(a));

    do {
        memcpy(a, backupA, sizeof(a));
        memset(check, 0, sizeof(check));
        for (int i = 0; i < wallIdx.size(); ++i) {
            if (wallIdx[i] == 1) {
                auto pos = wallList[i];
                a[pos.first][pos.second] = 1;  // 벽새우기
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j] == 2)
                    dfs(i, j);
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j] == 0) cnt++;
            }
        }
        safe = max(safe, cnt);

    } while (next_permutation(wallIdx.begin(), wallIdx.end()));

    cout << safe;
    return 0;
}
