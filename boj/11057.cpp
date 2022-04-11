#include <iostream>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
#define MOD 10007

int n, d[1001][10]; // d[i][j] = 길이i, j로 끝나는 오르막수 갯수

int main() {
    FASTIO;
    cin >> n;
    for (int j = 0; j < 10; ++j) {
        d[1][j] = 1;
    }

    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j < 10; ++j) {
            for (int k = 0; k <= j; ++k) {
                d[i][j] += d[i - 1][k];
                d[i][j] %= MOD;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < 10; ++i) {
        ans = (ans + d[n][i]) % MOD;
    }

    cout << ans;
    return 0;
}
