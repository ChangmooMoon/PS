#include <cstring>
#include <iostream>
#define INF 0x3f3f3f3f
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
using namespace std;

int n, m, a[101], d[101][101][2];

int main() {
    FASTIO;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    memset(d, -INF, sizeof(d));
    for (int i = 0; i <= n; ++i) {
        d[i][0][0] = 0;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            d[i][j][0] = max(d[i - 1][j][0], d[i - 1][j][1]);
            d[i][j][1] = max(d[i - 1][j - 1][0] + a[i], d[i - 1][j][1] + a[i]);
        }
    }

    cout << max(d[n][m][0], d[n][m][1]);
    return 0;
}