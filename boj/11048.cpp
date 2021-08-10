#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// dp방식 1
int n, m;  // 1000
int a[1001][1001];
int d[1001][1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

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
