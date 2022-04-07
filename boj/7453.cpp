#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
typedef long long ll;

int n; // 4000
ll a[4000][4], ans = 0;
vector<ll> d1, d2; // 4000^2

int main() {
    FASTIO;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            d1.push_back(a[i][0] + a[j][1]);
            d2.push_back(a[i][2] + a[j][3]);
        }
    }

    sort(d1.begin(), d1.end());
    sort(d2.begin(), d2.end());

    for (int i = 0; i < n * n; ++i) {
        ans +=
            upper_bound(d2.begin(), d2.end(), -d1[i]) - lower_bound(d2.begin(), d2.end(), -d1[i]);
    }

    cout << ans;
    return 0;
}
