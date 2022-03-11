#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
typedef pair<int, int> pii;

int n, t, ans;
vector<pii> a[100001];
bool check[100001];

void dfs(int now, int len) {
    check[now] = true;
    if (ans < len) {
        t = now;
        ans = len;
    }
    for (auto &[next, w] : a[now]) {
        if (check[next]) continue;
        dfs(next, len + w);
    }
}

int main() {
    FASTIO;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int u, v, w;
        cin >> u;
        while (1) {
            cin >> v;
            if (v == -1) break;
            cin >> w;
            a[u].push_back({v, w});
        }
    }
    dfs(1, 0);
    memset(check, false, sizeof(check));
    dfs(t, 0);
    cout << ans;
    return 0;
}
