#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define ll long long
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n, k;
int a[40];

ll solve() {
    int m = n / 2;  // v2
    n = n - m;      // v1
    vector<int> v1(1 << n), v2(1 << m);
    for (int i = 0; i < (1 << n); ++i) {
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) v1[i] += a[j];
        }
    }

    for (int i = 0; i < (1 << m); ++i) {
        for (int j = 0; j < m; ++j) {
            if (i & (1 << j)) v2[i] += a[n + j];
        }
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end(), greater<>());
    // 2^N * NlogN * 2 + N + M
    // 2^20 * 2^20
    n = 1 << n, m = 1 << m;
    int s = 0, e = 0;
    ll ans = 0;
    while (s < n && e < m) {
        if (v1[s] + v2[e] == k) {
            ll up = 1, down = 1;
            ++s, ++e;
            while (s < n && v1[s - 1] == v1[s]) {
                ++up;
                ++s;
            }
            while (e < m && v2[e - 1] == v2[e]) {
                ++down;
                ++e;
            }
            ans += up * down;
        } else if (v1[s] + v2[e] < k) {
            ++s;
        } else {
            ++e;
        }
    }
    if (k == 0) --ans;
    return ans;
}

int main() {
    FASTIO;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    cout << solve();
    return 0;
}
