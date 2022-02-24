#include <iostream>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
#define INF 0x3f3f3f3f
// 벨만포드, 음수사이클

vector<pii> a[501];
int n, m;
ll d[501];

bool go() {
    d[1] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int u = 1; u <= n; ++u) {
            for (auto &[v, w] : a[u]) {
                if (d[u] != INF && d[v] > d[u] + w) {
                    if (i == n) return false;
                    d[v] = d[u] + w;
                }
            }
        }
    }
    return true;
}

int main() {
    FASTIO;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        a[u].push_back({v, w});
    }
    for (int i = 1; i <= n; ++i) {
        d[i] = INF;
    }

    if (!go()) {
        cout << -1;
        return 0;
    }

    for (int i = 2; i <= n; ++i) {
        if (d[i] == INF) d[i] = -1;
        cout << d[i] << endl;
    }
    return 0;
}
