#include <iostream>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
typedef long long ll;

int n, k, a[100001];
ll d[100001];

int main() {
    FASTIO;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    int s = 1, e = 1;
    ll psum = a[1];
    while (s <= n && e <= n) {
        d[e] = max(d[e], d[e - 1]);
        if (psum >= k) {
            d[e] = max(d[e], d[s - 1] + psum - k);
            if (s < e)
                psum -= a[s++];
            else if (s++ == e)
                psum = a[++e];
        } else
            psum += a[++e];
    }

    cout << d[n];
    return 0;
}
