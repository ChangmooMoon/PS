#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n;
int a[101][101];
ll d[101][101];

// dp
ll go(int r, int c) {
    if (r == n - 1 && c == n - 1) return 1;
    if (r >= n || c >= n || a[r][c] == 0) return 0;

    ll &ret = d[r][c];
    if (ret != -1) return ret;

    ret = 0;
    ret += go(r + a[r][c], c) + go(r, c + a[r][c]);
    return ret;
}

int main() {
    FASTIO;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    memset(d, -1, sizeof(d));
    cout << go(0, 0);
    return 0;
}
