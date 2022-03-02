#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int t, n, k, fin;
vector<int> a[1001];
int ind[1001], w[1001];
int d[1001];
// 위상정렬

int tsort() {
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (!ind[i]) {
            q.push(i);
            d[i] = w[i];
        }
    }
    while (!q.empty()) {
        int now = q.front();
        if (now == fin) return d[fin];
        q.pop();
        for (int next : a[now]) {
            d[next] = max(d[next], d[now] + w[next]);
            --ind[next];
            if (!ind[next]) q.push(next);
        }
    }
    return -1;
}

int main() {
    FASTIO;
    cin >> t;
    while (t--) {
        memset(ind, 0, sizeof(ind));
        memset(d, 0, sizeof(d));
        for (int i = 1; i <= n; ++i) {
            a[i].clear();
        }
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) {
            cin >> w[i];
        }
        for (int i = 0; i < k; ++i) {
            int u, v;
            cin >> u >> v;
            a[u].push_back(v);
            ++ind[v];
        }
        cin >> fin;
        cout << tsort() << endl;
    }
    return 0;
}
