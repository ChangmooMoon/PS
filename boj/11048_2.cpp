#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

// dp방식 topdown
int n, m;  // 1000
int a[1001][1001];
int d[1001][1001];

int go(int i, int j) {
    if (i < 1 || j < 1) return 0;
    if (d[i][j] >= 0) return d[i][j];
    return d[i][j] = a[i][j] + max(go(i - 1, j), go(i, j - 1));
}

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

    memset(d, -1, sizeof(d));
    cout << go(n, m);

    return 0;
}
