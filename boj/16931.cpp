#include <algorithm>
#include <iostream>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n, m, x, y, z;  // up, left, front

int main() {
    FASTIO;
    cin >> n >> m;
    int a[105][105];

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            if (a[i][j]) ++x;  // up
        }
    }
    x *= 2;

    // left,right
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {  // left
            y += max(0, a[i][j] - a[i][j - 1]);
        }
        for (int j = m; j >= 1; --j) {
            y += max(0, a[i][j] - a[i][j + 1]);
        }
    }

    // front back
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            z += max(0, a[j][i] - a[j - 1][i]);
        }
        for (int j = n; j >= 1; --j) {
            z += max(0, a[j][i] - a[j + 1][i]);
        }
    }

    cout << x + y + z << endl;
    return 0;
}
