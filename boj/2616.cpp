#include <cstring>
#include <iostream>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
// dp, psum

int n, m;
int a[50001], d[3][50001];
// d[i][j] = max( d[i][j+1], d[i+1][j+m] + a[j+m-1] - a[j-1] );

int go(int loco, int idx) {
    if (loco == 3 || idx >= n) return 0;

    int &ret = d[loco][idx];
    if (ret != -1) return ret;

    ret = 0;
    if (idx + m - 1 <= n) {
        ret = max(go(loco, idx + 1), go(loco + 1, idx + m) + a[idx + m - 1] - a[idx - 1]);
    }
    return ret;
}

int main() {
    FASTIO;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    cin >> m;
    memset(d, -1, sizeof(d));
    cout << go(0, 1);
    return 0;
}
