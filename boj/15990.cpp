#include <iostream>
using namespace std;
#define mod 1'000'000'009

int t;
long long d[100'001][4];  // 1-(2,3), 2-(1,3), 3-(1,2)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    d[1][1] = d[2][2] = d[3][3] = 1;
    d[3][1] = d[3][2] = 1;

    for (int i = 4; i < 100'001; ++i) {
        d[i][1] = (d[i - 1][2] + d[i - 1][3]) % mod;
        d[i][2] = (d[i - 2][1] + d[i - 2][3]) % mod;
        d[i][3] = (d[i - 3][1] + d[i - 3][2]) % mod;
    }
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << (d[n][1] + d[n][2] + d[n][3]) % mod << '\n';
    }

    return 0;
}
