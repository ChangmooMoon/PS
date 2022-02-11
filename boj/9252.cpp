#include <iostream>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

string a, b;
int d[1001][1001], d2[1001][1001];

int main() {
    FASTIO;
    cin >> a >> b;
    int n = a.length(), m = b.length();
    a = ' ' + a, b = ' ' + b;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i] == b[j]) {
                d[i][j] = d[i - 1][j - 1] + 1;
                d2[i][j] = 1;
            } else {
                if (d[i - 1][j] > d[i][j - 1]) {
                    d[i][j] = d[i - 1][j];
                    d2[i][j] = 2;
                } else {
                    d[i][j] = d[i][j - 1];
                    d2[i][j] = 3;
                }
            }
        }
    }
    cout << d[n][m] << endl;
    string ans;
    while (n > 0 && m > 0) {
        if (d2[n][m] == 1) {
            ans += a[n];
            --n, --m;
        } else if (d2[n][m] == 2) {
            --n;
        } else
            --m;
    }
    for (int i = ans.length() - 1; i >= 0; --i) {
        cout << ans[i];
    }
    return 0;
}
