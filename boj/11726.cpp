#include <iostream>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
#define MOD 10007

int n, d[1001] = {0, 1, 2};
// d[i] = (d[i-1] + d[i-2]) % MOD

int main() {
    FASTIO;
    cin >> n;
    for (int i = 3; i <= n; ++i) {
        d[i] = (d[i - 1] + d[i - 2]) % MOD;
    }
    cout << d[n];
    return 0;
}
