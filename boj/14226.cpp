#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    int ans = -1;

    // 화면 모두복사,저장 s,c -> s,s
    // 클립보드 붙여넣기 s,c -> s+c, c
    // 화면 1개 삭제 s,c -> s-1,c

    vector<vector<int>> d(2001, vector<int>(2001, -1));
    queue<pair<int, int>> q;
    q.push({1, 0});
    d[1][0] = 0;

    while (!q.empty()) {
        auto& [s, c] = q.front();
        q.pop();
        if (d[s][s] == -1) {
            d[s][s] = d[s][c] + 1;
            q.push({s, s});
        }

        if (s + c <= n && d[s + c][c] == -1) {
            d[s + c][c] = d[s][c] + 1;
            q.push({s + c, c});
        }

        if (s >= 1 && d[s - 1][c] == -1) {
            d[s - 1][c] = d[s][c] + 1;
            q.push({s - 1, c});
        }
    }

    for (int i = 0; i <= n; ++i) {
        if (d[n][i] != -1) {
            if (ans == -1 || ans > d[n][i]) {
                ans = d[n][i];
            }
        }
    }

    cout << ans;

    return 0;
}
