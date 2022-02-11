#include <cstring>
#include <iostream>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
#define INF 0x3f3f3f3f

int n;
int a[1005], d[1005];

int go(int cur) {
    if (cur >= n) return INF;
    if (cur == n - 1) return 0;
    if (d[cur] != -1) return d[cur];

    d[cur] = INF;
    for (int i = 1; i <= a[cur]; ++i) {
        d[cur] = min(d[cur], go(cur + i) + 1);
    }
    return d[cur];
}

int main() {
    FASTIO;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    memset(d, -1, sizeof(d));
    int res = go(0);
    if (res == INF)
        cout << -1;
    else
        cout << res;
    return 0;
}
