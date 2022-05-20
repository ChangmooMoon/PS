#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
#define INF 0x3f3f3f3f

int n, mp, mf, ms, mv, ans = INF;
struct Food {
    int p, f, s, v, c;
} a[16];
vector<vector<int>> ans_v;

int main() {
    FASTIO;
    cin >> n >> mp >> mf >> ms >> mv;
    for (int i = 0; i < n; ++i) {
        int p, f, s, v, c;
        cin >> p >> f >> s >> v >> c;
        a[i] = {p, f, s, v, c};
    }

    for (int i = 1; i < (1 << n); ++i) {
        int p, f, s, v, c;
        p = f = s = v = c = 0;

        vector<int> ret;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                ret.push_back(j + 1);
                p += a[j].p;
                f += a[j].f;
                s += a[j].s;
                v += a[j].v;
                c += a[j].c;
            }
        }
        if (p >= mp && f >= mf && s >= ms && v >= mv) {
            if (ans > c) {
                ans = c;
                ans_v.clear();
                ans_v.push_back(ret);
            } else if (ans == c) {
                ans_v.push_back(ret);
            }
        }
    }

    if (ans == INF) {
        cout << -1;
    } else {
        cout << ans << endl;
        sort(ans_v.begin(), ans_v.end());
        for (int n : ans_v[0]) {
            cout << n << ' ';
        }
    }
    return 0;
}
