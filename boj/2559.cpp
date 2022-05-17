#include <bits/stdc++.h>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
#define INF 0x3f3f3f3f;

int n, k, a[100001], ans = -INF;

int main() {
    FASTIO;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        int tmp;
        cin >> tmp;
        a[i] = a[i - 1] + tmp;
    }

    for (int i = k; i <= n; ++i) {
        ans = max(ans, a[i] - a[i - k]);
    }
    cout << ans;
    return 0;
}
