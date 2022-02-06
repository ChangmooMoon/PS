#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
#define endl '\n'

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int n;
int a[25][25];  // 집1
bool check[25][25];
vector<int> ans;

int bfs(int i, int j) {
    int cnt = 0;
    queue<pii> q;
    q.push({i, j});
    check[i][j] = true;

    while (!q.empty()) {
        const auto& [r, c] = q.front();
        q.pop();
        ++cnt;
        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (0 > nr || nr >= n || 0 > nc || nc >= n) continue;
            if (!a[nr][nc] || check[nr][nc]) continue;

            q.push({nr, nc});
            check[nr][nc] = true;
        }
    }

    return cnt;
}

// 각 단지 집의 개수 출력
int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%1d", &a[i][j]);
        }
    }

    int group = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] == 1 && !check[i][j]) {
                ++group;
                ans.push_back(bfs(i, j));
            }
        }
    }
    sort(ans.begin(), ans.end());

    cout << group << endl;
    for (int i : ans) {
        cout << i << endl;
    }

    return 0;
}
