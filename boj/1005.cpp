#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

// tree dp
int t, n, k, fin;
int w[1001];
vector<int> a[1001];
int d[1001];

int dfs(int now) {
    int &ret = d[now];
    if (ret != -1) return ret;

    ret = w[now];
    for (int prev : a[now]) {
        ret = max(ret, dfs(prev) + w[now]);
    }
    return ret;
}

int main() {
    FASTIO;
    cin >> t;
    while (t--) {
        memset(d, -1, sizeof(d));
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
            a[v].push_back(u);
        }
        cin >> fin;
        cout << dfs(fin) << endl;
    }

    return 0;
}
