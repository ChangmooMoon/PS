#include <iostream>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
#define INF 0x3f3f3f3f

int n, m;
int a[1002], d[1002];

int calc(int s, int e) { return m - (e - s + a[e] - a[s - 1]); }

int main() {
    FASTIO;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] += a[i - 1];
    }

    for (int i = 1; i <= n; ++i) {
        d[i] = INF;
        for (int j = 0; j < i; ++j) {
            int space = calc(j + 1, i);
            if (space >= 0) {
                d[i] = min(d[i], d[j] + space * space);
            }
        }
    }

    int ans = INF;
    for (int i = 0; i < n; ++i) {
        if (calc(i + 1, n) >= 0)
            ans = min(ans, d[i]);
    }

    cout << ans;
    return 0;
}
