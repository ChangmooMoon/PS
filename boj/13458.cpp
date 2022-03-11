#include <iostream>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n, a[1000001], b, c;
long long ans = 0;

int main() {
    FASTIO;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cin >> b >> c;
    for (int i = 0; i < n; ++i) {
        a[i] = max(0, a[i] - b);
    }
    for (int i = 0; i < n; ++i) {
        ans += a[i] / c;
        if (a[i] % c) ++ans;
    }
    cout << ans + n;
    return 0;
}
