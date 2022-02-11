#include <iostream>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n, m;
int a[1005][1005], d[1005][1005];

int main() {
    FASTIO;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            d[i][j] = a[i][j] + max({d[i - 1][j], d[i][j - 1], d[i - 1][j - 1]});
        }
    }

    cout << d[n][m];
    return 0;
}
