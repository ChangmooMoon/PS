#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, m;
bool visit[2001];
vector<int> adj[2001];
int result = 0;

void dfs(int node, int i) {
    visit[node] = true;  // 방문 체크
    if (i == 4) {
        result = 1;
        return;
    }
    for (int next : adj[node]) {
        if (visit[next])
            continue;  // 방문했으면 중단
        else
            dfs(next, i + 1);
    }
    visit[node] = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    for (int i = 0; i < n; ++i) {
        if (result) break;
        dfs(i, 0);
    }
    cout << result << '\n';
    return 0;
}
