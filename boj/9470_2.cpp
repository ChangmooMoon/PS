#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int t, k, m, p;
vector<int> a[1001];
int order[1001];
// 위상정렬 dfs

int go(int x) {
    int &ret = order[x], cnt;
    if (ret != -1) return ret;

    ret = 1, cnt = 0;
    for (int y : a[x]) {
        int tmp = go(y);
        if (tmp > ret) {
            ret = tmp;
            cnt = 0;
        }
        if (tmp == ret) ++cnt;
    }
    return ret += (cnt > 1);
}

int main() {
    FASTIO;
    cin >> t;
    while (t--) {
        memset(order, -1, sizeof(order));
        for (int i = 1; i <= m; ++i) {
            a[i].clear();
        }
        cin >> k >> m >> p;
        for (int i = 0; i < p; ++i) {
            int u, v;
            cin >> u >> v;
            a[v].push_back(u);
        }
        cout << k << ' ' << go(m) << endl;
    }

    return 0;
}
