#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n;
vector<int> g[3005];
int ind[3005];  // ind[i]가 2이상이면 사이클
int d[3005];

void bfs() {  // ind 1씩 감소시키면서 ind 2인 정점만 남음
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (ind[i] == 1) q.push(i);
    }
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        --ind[x];
        for (int y : g[x]) {
            if (ind[y]) {
                --ind[y];
                if (ind[y] == 1) q.push(y);
            }
        }
    }
}

void dfs(int x, int p) {
    for (int y : g[x]) {
        if (ind[y] || y == p) continue;
        d[y] = d[x] + 1;
        dfs(y, x);
    }
}

int main() {
    FASTIO;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        ++ind[u], ++ind[v];
    }

    bfs();
    for (int i = 1; i <= n; ++i) {
        if (ind[i]) dfs(i, -1);
    }
    for (int i = 1; i <= n; ++i) {
        cout << d[i] << ' ';
    }
    return 0;
}
