#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n;
vector<int> a[10001];
int d[10001][2], w[10001];

int go(int now, bool b, int prev) {
    int &ret = d[now][b];
    if (ret != -1) return ret;

    ret = w[now] * b;
    for (int next : a[now]) {
        if (next == prev) continue;
        if (b)
            ret += go(next, false, now);
        else
            ret += max(go(next, true, now), go(next, false, now));
    }
    return ret;
}

int main() {
    FASTIO;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> w[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v), a[v].push_back(u);
    }
    memset(d, -1, sizeof(d));
    cout << max(go(1, false, 0), go(1, true, 0));
    return 0;
}
