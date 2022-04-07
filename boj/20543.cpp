#include <iostream>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
typedef long long ll;

int n, m;
ll a[2001][2001]; // 해발고도
ll d[2001][2001];

int main() {
    FASTIO;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            a[i][j] *= -1;
        }
    }
    // d[i][j] = a[i-r][j-r] - a[i-r-1][j-r] - a[i-r][j-r-1] + d[i-m][j] + d[i][j-m] - d[i-m][j-m];
    int r = m / 2;
    for (int i = r; i < n - r; ++i) {
        for (int j = r; j < n - r; ++j) {
            d[i][j] = a[i - r][j - r];
            if (i - r - 1 >= 0) d[i][j] -= a[i - r - 1][j - r];
            if (j - r - 1 >= 0) d[i][j] -= a[i - r][j - r - 1];
            if (i - r - 1 >= 0 && j - r - 1 >= 0) d[i][j] += a[i - r - 1][j - r - 1];
            if (i - m >= 0) d[i][j] += d[i - m][j];
            if (j - m >= 0) d[i][j] += d[i][j - m];
            if (i - m >= 0 && j - m >= 0) d[i][j] -= d[i - m][j - m];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << d[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}
