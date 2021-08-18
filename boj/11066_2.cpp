#include <cstring>
#include <iostream>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
#define INF 0x3f3f3f3f

int a[501];
int psum[501];
int d[501][501];  // i~j까지 합칠때 최소비용
// d[i][j] = d[i][k] + d[k+1][j] + a[i]~a[j]까지의 합, (i-j > 2)
// d[1][5] = d[1][2] + d[3][5] + (a[1]~a[5]) 까지 부분합
//         = d[1][3] + d[4][5] + (a[1]~a[5]) 까지의 부분합
// d[1][2] = a[1] + a[2]

int main() {
    FASTIO;
    int t;
    cin >> t;

    while (t--) {
        memset(d, INF, sizeof(d));
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            psum[i] = psum[i - 1] + a[i];
            d[i][i] = 0;
        }

        for (int k = 1; k < n; ++k) {
            for (int i = 1; i <= n - k; ++i) {
                int& target = d[i][i + k];

                for (int j = i; j < i + k; ++j) {
                    target = min(target, d[i][j] + d[j + 1][i + k]);
                }

                target += psum[i + k] - psum[i - 1];
            }
        }

        cout << d[1][n] << endl;
    }

    return 0;
}
