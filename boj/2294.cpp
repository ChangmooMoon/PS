#include <cstring>
#include <iostream>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
#define INF 0x3f3f3f3f
// dp

int n, k;  // k원 만들기
int a[105], d[10005];

int main() {
    FASTIO;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    memset(d, INF, sizeof(d));

    d[0] = 0;
    for (int i = 0; i < n; ++i) {
        int cur = a[i];
        for (int j = cur; j <= k; ++j) {
            d[j] = min(d[j], d[j - cur] + 1);
        }
    }

    if (d[k] == INF)
        cout << -1;
    else
        cout << d[k];
    return 0;
}
