#include <bits/stdc++.h>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
// 두 수의 합
int n, a[100001], x, ans;

int main() {
    FASTIO;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cin >> x;
    sort(a, a + n);

    int s = 0, e = n - 1;
    while (s < e) {
        if (a[s] + a[e] == x) {
            ++ans;
            --e;
        } else if (a[s] + a[e] > x)
            --e;
        else if (a[s] + a[e] < x)
            ++s;
    }
    cout << ans;
    return 0;
}
