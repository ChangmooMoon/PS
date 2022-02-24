#include <cstring>
#include <iostream>
#include <tuple>
using namespace std;
typedef long long ll;
typedef tuple<int, int, int> tiii;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
#define INF 0x3f3f3f3f
// 벨만포드, 음수사이클

int n, m;
tiii a[6001];
ll d[501];

void go() {
    d[1] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < m; ++j) {
            int u, v, w;
            tie(u, v, w) = a[j];
            if (d[u] != INF && d[v] > d[u] + w) {
                if (i == n) {
                    cout << -1;
                    return;
                }
                d[v] = d[u] + w;
            }
        }
    }
    for (int i = 2; i <= n; ++i) {
        if (d[i] == INF) d[i] = -1;
        cout << d[i] << endl;
    }
}

int main() {
    FASTIO;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        a[i] = {u, v, w};
    }
    for (int i = 0; i <= n; ++i) {
        d[i] = INF;
    }
    go();
    return 0;
}
