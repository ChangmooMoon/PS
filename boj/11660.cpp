#include <iostream>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n, m;
int a[1025][1025];

int main() {
    FASTIO;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
            a[i][j] += a[i][j - 1];
        }
    }
    for (int j = 1; j <= n; ++j) {
        for (int i = 1; i <= n; ++i) {
            a[i][j] += a[i - 1][j];
        }
    }

    for (int i = 0; i < m; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << a[x2][y2] - a[x1 - 1][y2] - a[x2][y1 - 1] + a[x1 - 1][y1 - 1] << endl;
    }

    return 0;
}
