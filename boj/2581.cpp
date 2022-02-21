#include <iostream>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int m, n, sum, mn = 10001;
bool check[10001];

int main() {
    FASTIO;
    cin >> m >> n;
    check[0] = check[1] = true;
    for (int i = 2; i * i <= n; ++i) {
        if (!check[i]) {
            for (int j = i * 2; j <= n; j += i) {
                check[j] = true;
            }
        }
    }
    for (int i = m; i <= n; ++i) {
        if (!check[i]) {
            sum += i;
            if (mn > i) mn = i;
        }
    }

    if (sum == 0) {
        cout << -1;
        return 0;
    }
    cout << sum << endl << mn;
    return 0;
}
