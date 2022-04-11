#include <iostream>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n, a[1001], d[1001][2];
// d[i][0] = max(d[i-2][0], d[i-2][1]) + a[i]
// d[i][1] = d[i-1][0] + a[i];

int main() {
    FASTIO;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i]; // 점수
    }

    d[1][1] = a[1];
    d[2][0] = a[2];
    d[2][1] = a[1] + a[2];

    for (int i = 3; i <= n; ++i) {
        d[i][0] = max(d[i - 2][0], d[i - 2][1]) + a[i];
        d[i][1] = d[i - 1][0] + a[i];
    }

    cout << max(d[n][0], d[n][1]);
    return 0;
}
