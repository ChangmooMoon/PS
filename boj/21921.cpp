#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
#define INF 0x3f3f3f3f

int n, x, a[250001], psum[250001];

int main() {
    FASTIO;
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= x; ++i) {
        psum[x] += a[i];
    }

    int maxVisit = psum[x];
    int cnt = 1;

    for (int i = x + 1; i <= n; ++i) {
        psum[i] = psum[i - 1] + a[i] - a[i - x];
        if (maxVisit < psum[i]) {
            maxVisit = psum[i];
            cnt = 1;
        } else if (maxVisit == psum[i]) {
            ++cnt;
        }
    }

    if (maxVisit == 0)
        cout << "SAD";
    else
        cout << maxVisit << endl << cnt;
    return 0;
}
