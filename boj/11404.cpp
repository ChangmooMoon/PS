#include <algorithm>
#include <iostream>
using namespace std;
#define INF 987654321

int n, m;         // 100, 100000
int d[101][101];  // 100000

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;

        if (!d[u][v])
            d[u][v] = c;
        else
            d[u][v] = min(d[u][v], c);  // 모든 노드간 최단경로비용
    }

    for (int w = 1; w <= n; ++w) {
        for (int u = 1; u <= n; ++u) {
            for (int v = 1; v <= n; ++v) {
                if (!d[u][w] || !d[w][v] || u == v) continue;
                if (!d[u][v] || d[u][w] + d[w][v] < d[u][v]) {  //
                    d[u][v] = d[u][w] + d[w][v];
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << d[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
