#include <bits/stdc++.h>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n, m, u, v, cnt;
vector<int> a[1001];
bool visited[1001];

void dfs(int curr) {
    if(visited[curr]) return;
    visited[curr] = true;

    for(int next: a[curr]) {
        dfs(next);
    }
}

int main() {
    FASTIO;
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    for(int i = 1; i <= n; ++i) {
        if(visited[i]) continue;
        dfs(i);
        ++cnt;
    }

    cout << cnt;
    return 0;
}
