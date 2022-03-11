#include <iostream>
#include <numeric>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
#define INF 0x3f3f3f3f

//플로이드

int n, m, d[101][101];

int main() {
    FASTIO;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j) continue;
            d[i][j] = INF;
        }
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        d[u][v] = d[v][u] = 1;
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i == j) continue;
                if (d[i][j] > d[i][k] + d[k][j]) d[i][j] = d[i][k] + d[k][j];
            }
        }
    }

    int min = INF, ans = -1;
    for (int i = 1; i <= n; ++i) {
        int sum = accumulate(d[i] + 1, d[i] + n + 1, 0);
        if (min > sum) {
            min = sum;
            ans = i;
        }
    }
    cout << ans;
    return 0;
}
