#include <iostream>

using namespace std;
#define mod 1'000'000'009

int t;
long long d[1'000'001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    d[0] = 1;
    d[1] = 1;
    d[2] = 2;
    for (int i = 3; i < 1'000'001; ++i)
        d[i] = (d[i - 1] + d[i - 2] + d[i - 3]) % mod;

    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        cout << d[n] << '\n';
    }

    return 0;
}
