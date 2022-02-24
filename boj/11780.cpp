#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
#define INF 0x3f3f3f3f
// 플로이드, 경로

int n, m;
int d[101][101], path[101][101];

void go(int u, int v) {
    queue<int> q;
    q.push(u);
    while (u != v) {
        u = path[u][v];
        q.push(u);
    }
    cout << q.size() << ' ';
    while (!q.empty()) {
        cout << q.front() << ' ';
        q.pop();
    }
    cout << endl;
}

int main() {
    FASTIO;
    cin >> n >> m;
    memset(d, INF, sizeof(d));
    for (int i = 1; i <= n; ++i) {
        d[i][i] = 0;
    }
    memset(path, -1, sizeof(path));

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        if (d[u][v] > w) {
            d[u][v] = w;
            path[u][v] = v;
        }
    }

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i == j) continue;
                if (d[i][j] > d[i][k] + d[k][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                    path[i][j] = path[i][k];
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (d[i][j] == INF)
                cout << 0 << ' ';
            else
                cout << d[i][j] << ' ';
        }
        cout << endl;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j || d[i][j] == INF || path[i][j] == -1)
                cout << 0 << endl;
            else
                go(i, j);
        }
    }
    return 0;
}
