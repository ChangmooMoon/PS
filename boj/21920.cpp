#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
#define INF 0x3f3f3f3f

int n, x;
int cnt, a[500001];
double sum;

int main() {
    FASTIO;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cin >> x;

    for (int i = 0; i < n; ++i) {
        if (gcd(a[i], x) == 1) {
            ++cnt;
            sum += a[i];
        }
    }

    cout.unsetf(ios::fixed);
    cout.precision(6);
    cout << sum / cnt;
    return 0;
}
