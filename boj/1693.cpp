#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
#define INF 0x3f3f3f3f

// tree dp
int n, ans = INF;
vector<int> a[100001];
int d[100001][17]; // d[i][color]
// c = log2(100000)

int solve(int now, int color, int prev) {
    int &ret = d[now][color];
    if (ret != -1) return ret;

    ret = color;
    for (int next : a[now]) {
        if (next == prev) continue;
        int sub = INF;
        for (int i = 1; i < 17; ++i) {
            if (i == color) continue;
            sub = min(sub, solve(next, i, now));
        }
        ret += sub;
    }
    return d[now][color] = ret;
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
    for (int i = 1; i < 17; ++i) {
        ans = min(ans, solve(1, i, 0));
    }
    cout << ans;
    return 0;
}
