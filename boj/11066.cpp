#include <cstring>
#include <iostream>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int t, k, a[501], d[501][501];
// d[i][j] = min(d[i][k] + d[k+1][j] + i~j까지 합)

int go(int s, int e) {
    if (s == e) return 0;

    int &ret = d[s][e];
    if (ret != -1) return ret;

    int sum = 0;
    for (int k = s; k <= e; ++k) {
        sum += a[k];
    }
    for (int k = s; k <= e - 1; ++k) {
        int tmp = go(s, k) + go(k + 1, e) + sum;
        if (ret == -1 || ret > tmp) ret = tmp;
    }
    return ret;
}

int main() {
    FASTIO;
    cin >> t;
    while (t--) {
        cin >> k;
        for (int i = 1; i <= k; ++i) {
            cin >> a[i];
        }
        memset(d, -1, sizeof(d));
        cout << go(1, k) << endl;
    }
    return 0;
}
