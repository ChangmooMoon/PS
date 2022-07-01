#include <bits/stdc++.h>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n, m, a[101], d[101][101], psum[101];

int go(int n, int m) { // idx, group
    if (m == 0) return 0;
    if (n <= 0) return -32768 * 100;

    int &ret = d[n][m];
    if (ret != -1) return ret;

    ret = go(n - 1, m);
    for (int k = n; k >= 1; --k) {
        ret = max(ret, go(k - 2, m - 1) + psum[n] - psum[k] + a[k]);
    }
    return ret;
}

int main() {
    FASTIO;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
   j   psum[i] = psum[i - 1] + a[i];
    }
    memset(d, -1, sizeof(d));
    cout << go(n, m);
    return 0;
}

alksjdfkladsjfkladsckdanalkdjsfklajsdfkljasdlfkjdsalfkjdsakljlkjkjj