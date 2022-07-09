#include <bits/stdc++.h>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n, m;
long long total, ans;
tuple<int, int, int> a[500001];
int p[100001];

int Find(int x) {
    if (x == p[x]) return x;
    return p[x] = Find(p[x]);
}

void Union(int x, int y) {
    int X = Find(x);
    int Y = Find(y);
    if (X < Y)
        p[Y] = X;
    else
        p[X] = Y;
}

int main() {
    FASTIO;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        a[i] = {w, u, v};
        total += w;
    }
    sort(a, a + m);

    for (int i = 1; i <= n; ++i) {
        p[i] = i;
    }

    for (int i = 0; i < m; ++i) {
        int w, u, v;
        tie(w, u, v) = a[i];
        int x = Find(u), y = Find(v);
        if (Find(x) != Find(y)) {
            Union(x, y);
            ans += w;
        }
    }

    for (int i = 2; i <= n; ++i) {
        if (Find(1) != Find(i)) {
            cout << -1;
            return 0;
        }
    }

    cout << total - ans;
    return 0;
}
