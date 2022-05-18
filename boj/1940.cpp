#include <bits/stdc++.h>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n, m, ans = 0;
int a[15001];
bool check[15001];

void go(int idx, int cnt, int sum) {
    if (cnt == 2) {
        if (sum == m) ++ans;
        return;
    }

    for (int i = idx; i < n; ++i) {
        if (check[i]) continue;
        check[i] = true;
        go(i, cnt + 1, sum + a[i]);
        check[i] = false;
    }
}

int main() {
    FASTIO;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    go(0, 0, 0);
    cout << ans;
    return 0;
}
