#include <iostream>
#include <vector>
using namespace std;

int n, m;  // node 1000, edge 1,000,000
vector<int> a[1001];
vector<int> check(1001);
int ans = 0;

void dfs(int x) {
    check[x] = 1;
    for (int i = 0; i < a[x].size(); ++i) {
        int y = a[x][i];
        if (!check[y]) {
            dfs(y);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        a[u].emplace_back(v);
        a[v].emplace_back(u);
    }

    for (int i = 1; i <= n; ++i) {
        if (!check[i]) {
            dfs(i);
            ans++;
        }
    }
    cout << ans;

    return 0;
}
