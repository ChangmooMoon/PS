#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m, v;  // node 1000, edge 10000, start
vector<int> check(1001);
vector<int> a[1001];

void dfs(int x) {
    check[x] = 1;
    cout << x << ' ';
    for (int i = 0; i < a[x].size(); ++i) {
        int y = a[x][i];
        if (!check[y]) {
            dfs(y);
        }
    }
}

void bfs(int x) {
    fill(check.begin(), check.end(), 0);
    queue<int> q;
    q.push(x);
    check[x] = 1;

    while (!q.empty()) {
        int now = q.front();
        cout << now << ' ';
        q.pop();
        for (int i = 0; i < a[now].size(); ++i) {
            int y = a[now][i];
            if (!check[y]) {
                q.push(y);
                check[y] = true;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m >> v;

    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        a[u].emplace_back(v);
        a[v].emplace_back(u);
    }
    for (int i = 1; i <= n; ++i) {
        sort(a[i].begin(), a[i].end());
    }

    dfs(v);
    cout << '\n';
    bfs(v);
    return 0;
}
