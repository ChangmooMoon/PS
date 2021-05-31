#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
vector<int> tree[50001];
vector<int> depth(50001);
vector<bool> check(50001);
vector<int> parent(50001);

int lca(int u, int v) {
    if (depth[u] < depth[v]) {
        swap(u, v);  // 노드u의 레벨이 항상 더 크다고 가정
    }
    while (depth[u] != depth[v]) {
        u = parent[u];
    }
    while (u != v) {
        u = parent[u];
        v = parent[v];
    }

    return u;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    depth[1] = 0;  // 1번 노드가 루트
    check[1] = true;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int y : tree[x]) {
            if (check[y]) continue;
            depth[y] = depth[x] + 1;
            check[y] = true;
            parent[y] = x;
            q.push(y);
        }
    }

    cin >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << '\n';
    }
    return 0;
}
