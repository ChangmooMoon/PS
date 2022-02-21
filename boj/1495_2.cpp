#include <cstring>
#include <iostream>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n, s, m;
int a[101], d[101][1001];

// dp
int go(int vol, int idx) {
    if (vol < 0 || vol > m) return -2;
    if (idx == n) return vol;

    int &ret = d[idx][vol];
    if (ret != -1) return ret;

    return ret = max(go(vol - a[idx], idx + 1), go(vol + a[idx], idx + 1));
}

int main() {
    FASTIO;
    cin >> n >> s >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    memset(d, -1, sizeof(d));
    int ans = go(s, 0);
    if (ans == -2)
        cout << -1;
    else
        cout << ans;
    return 0;
}