#include <iostream>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n, m, ans;
int a[501];

int main() {
    FASTIO;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
    }

    for (int p = 1; p < m - 1; ++p) {
        int s = 0, e = 0;
        for (int i = 0; i < p; ++i)
            s = max(s, a[i]);
        for (int i = m - 1; i > p; --i) {
            e = max(e, a[i]);
        }
        ans += max(0, min(s, e) - a[p]);
    }
    cout << ans;
    return 0;
}
