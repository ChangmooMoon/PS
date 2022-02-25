#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

// tree dp
int n;
vector<int> a[1000001];
int d[1000001][2];

int dfs(int now, bool b, int prev) {
    int &ret = d[now][b];
    if (ret != -1) return ret;

    int ans = b;
    for (int next : a[now]) {
        if (next == prev) continue;
        if (b)
            ans += min(dfs(next, true, now), dfs(next, false, now));
        else
            ans += dfs(next, true, now);
    }
    return ret = ans;
}

int main() {
    FASTIO;
    memset(d, -1, sizeof(d));
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v), a[v].push_back(u);
    }

    cout << min(dfs(1, true, 0), dfs(1, false, 0));
    return 0;
}
