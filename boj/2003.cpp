#include <iostream>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n, m;
int a[10005];

int main() {
    FASTIO;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // O(n^2) 미만
    int s = 0, e = 0, ans = 0, sum = a[0];
    while (e < n) {
        if (sum == m) ++ans;
        if (sum <= m) {
            sum += a[++e];
        } else {
            sum -= a[s++];
        }
    }
    cout << ans;
    return 0;
}
