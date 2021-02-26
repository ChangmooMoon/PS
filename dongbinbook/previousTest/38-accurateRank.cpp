#include <algorithm>
#include <iostream>
using namespace std;
#define INF 987654321

int n, m;  // 학생수500, 비교횟수10000;
int d[501][501];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i <= 500; ++i) {
        for (int j = 0; j <= 500; ++j) {
            if (i == j)
                d[i][j] = 0;
            else
                d[i][j] = INF;
        }
    }

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        d[u][v] = 1;
    }
    // 1<5, 3<4, 4<2, 4<6, 5<2, 5<4;

    for (int w = 1; w <= n; ++w) {
        for (int u = 1; u <= n; ++u) {
            for (int v = 1; v <= n; ++v) {
                d[u][v] = min(d[u][v], d[u][w] + d[w][v]);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int cnt = 0;
        for (int j = 1; j <= n; ++j) {
            if (d[i][j] != INF || d[j][i] != INF) {
                ++cnt;
            }
            if (cnt == n) {
                ++ans;
            }
        }
    }

    cout << ans << '\n';
    return 0;
}

// 이분탐색으로도 풀수 있겠다.