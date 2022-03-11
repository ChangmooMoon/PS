#include <cstring>
#include <iostream>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n, a[301], d[301][2];

int go(int now, int step) {
    int &ret = d[now][step];
    if (ret != -1) return ret;

    if (step == 0)
        return ret = max(go(now - 2, 0), go(now - 2, 1)) + a[now];
    else
        return ret = go(now - 1, 0) + a[now];
}

int main() {
    FASTIO;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    memset(d, -1, sizeof(d));
    cout << max(go(n, 0), go(n, 1));
    return 0;
}
