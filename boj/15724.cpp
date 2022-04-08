#include <iostream>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n, m, a[1025][1025];
int k, r1, c1, r2, c2;

int main() {
    FASTIO;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            a[i][j] += a[i][j - 1];
        }
    }

    for (int j = 1; j <= m; ++j) {
        for (int i = 1; i <= n; ++i) {
            a[i][j] += a[i - 1][j];
        }
    }

    cin >> k;
    while (k--) {
        cin >> r1 >> c1 >> r2 >> c2;
        cout << a[r2][c2] - a[r2][c1 - 1] - a[r1 - 1][c2] + a[r1 - 1][c1 - 1] << endl;
    }

    return 0;
}
