#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n, m, cmd, a, b;
int p[1000001];

int Find(int x) {
    if (x == p[x]) return x;
    return p[x] = Find(p[x]);
}

void Union(int a, int b) {
    a = Find(a), b = Find(b);
    if (a < b)
        p[b] = p[a];
    else
        p[a] = b;
}

int main() {
    FASTIO;
    cin >> n >> m;
    for (int i = 0; i <= n; ++i) {
        p[i] = i;
    }

    for (int i = 0; i < m; ++i) {
        cin >> cmd >> a >> b;
        if (cmd == 0)
            Union(a, b);
        else {
            if (Find(a) == Find(b))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }

    return 0;
}
