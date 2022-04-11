#include <iostream>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
#define INF 0x3f3ff3f

int t, n, a[501], d[501][501]; // i~j까지 합칠때 최소비용
// d[i][j] = d[i][k] + d[k+1][j] + a[i]~a[j]까지의 합, (i-j > 2)
// d[1][5] = d[1][2] + d[3][5] + (a[1]~a[5]) 까지 부분합
//         = d[1][3] + d[4][5] + (a[1]~a[5]) 까지의 부분합
// d[1][2] = a[1] + a[2]

int main() {
    FASTIO;
    cin >> t;
    while (t--) {
        memset(d, INF, sizeof(d));
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            a[i] += a[i - 1];
            d[i][i] = 0;
        }

        for (int k = 1; k < n; ++k) {
            for (int i = 1; i <= n - k; ++i) {
                int &target = d[i][i + k];
                for (int j = i; j < i + k; ++j) {
                    target = min(target, d[i][j] + d[j + 1][i + k]);
                }
                target += a[i + k] - a[i - 1];
            }
        }

        cout << d[1][n] << endl;
    }

    return 0;
}
