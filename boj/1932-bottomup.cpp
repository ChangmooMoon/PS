#include <algorithm>
#include <iostream>
using namespace std;

int n;
int a[501][501];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            if (j == 1)
                a[i][j] += a[i - 1][j];
            else if (j == n)
                a[i][j] += a[i - 1][j - 1];
            else
                a[i][j] += max(a[i - 1][j], a[i - 1][j - 1]);
        }
    }

    int ans = -1;
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, a[n][i]);
    }

    cout << ans;

    return 0;
}
