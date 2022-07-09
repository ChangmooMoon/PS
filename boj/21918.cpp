#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
#define INF 0x3f3f3f3f

int n, m, a[4001];

void go(int cmd, int fi, int se) {
    if (cmd == 1) {
        a[fi] = se;
    } else if (cmd == 2) {
        for (int i = fi; i <= se; ++i) {
            a[i] = !a[i];
        }
    } else if (cmd == 3) {
        for (int i = fi; i <= se; ++i) {
            a[i] = 0;
        }
    } else {
        for (int i = fi; i <= se; ++i) {
            a[i] = 1;
        }
    }
}

int main() {
    FASTIO;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; ++i) {
        int cmd, fi, se;
        cin >> cmd >> fi >> se;
        go(cmd, fi, se);
    }

    for (int i = 1; i <= n; ++i) {
        cout << a[i] << ' ';
    }
    return 0;
}
