#include <iostream>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
#define INF 987654321

int n, l, r, x;
int a[15];
// 부르트포스
int go(int idx, int cnt, int sum, int mn, int mx) {
    if (idx == n) {
        if (cnt >= 2 && l <= sum && sum <= r && mx - mn >= x) return 1;
        return 0;
    }

    return go(idx + 1, cnt + 1, sum + a[idx], min(mn, a[idx]), max(mx, a[idx])) +
           go(idx + 1, cnt, sum, mn, mx);
}

int main() {
    FASTIO;
    cin >> n >> l >> r >> x;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    cout << go(0, 0, 0, INF, 0);

    return 0;
}
