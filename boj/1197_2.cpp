#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
// mst, prim
struct E {
    int v, w;
    bool operator<(const E &other) const { return w > other.w; }
};

int n, m;
vector<E> a[10001];
bool check[10001];

int solve() {
    int ret = 0;
    priority_queue<E> q;
    q.push({1, 0}); // v, w

    while (!q.empty()) {
        int v = q.top().v;
        int w = q.top().w;
        q.pop();
        if (check[v]) continue;

        check[v] = true;
        ret += w;
        for (E e : a[v]) {
            q.push(e);
        }
    }

    return ret;
}

int main() {
    FASTIO;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        a[u].push_back({v, w});
        a[v].push_back({u, w});
    }
    cout << solve();
    return 0;
}
