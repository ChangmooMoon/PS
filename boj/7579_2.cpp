#include <cstring>
#include <iostream>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n, m, a[101], c[101], d[101][10001];

int go(int now, int cost) {
    if (now == 0) return 0;
    int &ret = d[now][cost];
    if (ret != -1) return ret;

    ret = go(now - 1, cost);
    if (cost >= c[now - 1]) ret = max(ret, go(now - 1, cost - c[now - 1]) + a[now - 1]);
    return ret;
}

int main() {
    FASTIO;
    memset(d, -1, sizeof(d));
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    int s = 0, e = 10000;
    while (s < e) {
        int mid = (s + e) / 2;
        if (go(n, mid) >= m)
            e = mid;
        else
            s = mid + 1;
    }
    cout << s;
    return 0;
}
