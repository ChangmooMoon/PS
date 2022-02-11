#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n, m;
vector<int> a[32001];
int ind[32001];

void solve() {
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (!ind[i]) q.push(i);
    }

    while (!q.empty()) {
        int cur = q.front();
        cout << cur << ' ';
        q.pop();
        for (int i : a[cur]) {
            --ind[i];
            if (!ind[i]) q.push(i);
        }
    }
}

int main() {
    FASTIO;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        ++ind[v];
    }

    solve();
    return 0;