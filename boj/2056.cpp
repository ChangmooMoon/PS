#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n;
int t[10001], ind[10001], d[10001];
vector<int> a[10001];

int solve() {
    int ret;
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (!ind[i]) {
            q.push(i);
            d[i] = t[i];
        }
    }

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (int y : a[x]) {
            --ind[y];
            if (d[y] < d[x] + t[y]) d[y] = d[x] + t[y];
            if (!ind[y]) q.push(y);
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (ret < d[i]) ret = d[i];
    }
    return *max_element(d + 1, d + n + 1);
}

int main() {
    FASTIO;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int len;
        cin >> t[i] >> len;
        for (int j = 0; j < len; ++j) {
            int x;
            cin >> x;
            a[x].push_back(i);
            ++ind[i];
        }
    }

    cout << solve();
    return 0;
}
