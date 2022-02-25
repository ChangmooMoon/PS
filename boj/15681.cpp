#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

// tree dp
int n, r, q;
vector<int> a[100001];
vector<int> d(100001, 1);

int dfs(int cur, int p) {
    for (int next : a[cur]) {
        if (next != p) d[cur] += dfs(next, cur);
    }
    return d[cur];
}

int main() {
    FASTIO;
    cin >> n >> r >> q;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    dfs(r, 0);
    while (q--) {
        int u;
        cin >> u;
        cout << d[u] << endl;
    }
    return 0;
}