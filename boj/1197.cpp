#include <iostream>
#include <tuple>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
// mst, kruskal
int n, m;
tuple<int, int, int> a[100001];
int p[10001];

int Find(int x) {
    if (x = p[x])
        return x;
    else {
        int y = Find(p[x]);
        p[x] = y;
        return y;
    }
}

int main() {
    FASTIO;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        a[i] = {w, u, v};
    }
    sort(a, a + m);
    for (int i = 1; i <= n; ++i) {
        p[i] = i;
    }

    int ans = 0;
    for (int i = 0; i < m; ++i) {
        int w, u, v;
        tie(w, u, v) = a[i];
        int x = Find(u), y = Find(v);
        if (x != y) {
            p[x] = y;
            ans += w;
        }
    }

    cout << ans;
    return 0;
}
