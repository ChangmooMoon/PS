#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
#define MOD 1000000007

int n, a, b, c; // a, b, c, ab, ac, bc, abc
ll d[51][51][51][51];

ll go(int n, int a, int b, int c) {
    if (n == 0) {
        if (a == 0 && b == 0 && c == 0)
            return 1;
        else
            return 0;
    }
    if (a < 0 || b < 0 || c < 0) {
        return 0;
    }

    ll &ans = d[n][a][b][c];
    if (ans != -1)
        return ans;

    ans = 0;
    for (int i = 0; i <= 1; ++i) {
        for (int j = 0; j <= 1; ++j) {
            for (int k = 0; k <= 1; ++k) {
                if (i == 0 && j == 0 && k == 0)
                    continue;
                ans += go(n - 1, a - i, b - j, c - k);
                ans %= MOD;
            }
        }
    }
    return ans;
}

int main() {
    FASTIO;
    cin >> n >> a >> b >> c;
    memset(d, -1, sizeof(d));
    cout << go(n, a, b, c);
    return 0;
}
