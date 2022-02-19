#include <cstring>
#include <iostream>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int t, n;
int a[101][101], d[101][101];

int solve(int r, int c) {
    if (r == n) return a[r][c];
    int& ret = d[r][c];
    if (ret != -1) return ret;
    return ret = a[r][c] + max(solve(r + 1, c), solve(r + 1, c + 1));
}

int main() {
    FASTIO;
    cin >> t;
    while (t--) {
        memset(d, -1, sizeof(d));
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                cin >> a[i][j];
            }
        }
        cout << solve(1, 1) << endl;
    }

    return 0;
}
