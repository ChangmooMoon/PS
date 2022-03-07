#include <algorithm>
#include <iostream>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n, m, t, a[500001];
int main() {
    FASTIO;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> t;
        cout << upper_bound(a, a + n, t) - lower_bound(a, a + n, t) << ' ';
    }
    return 0;
}
