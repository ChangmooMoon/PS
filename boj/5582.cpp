#include <iostream>
#include <string>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

string a, b;
int d[4005][4005];

int main() {
    FASTIO;
    cin >> a >> b;
    int n = a.length(), m = b.length();
    a = ' ' + a, b = ' ' + b;

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i] == b[j]) {
                d[i][j] = d[i - 1][j - 1] + 1;
                if (ans < d[i][j]) ans = d[i][j];
            }
        }
    }

    cout << ans;
    return 0;
}
