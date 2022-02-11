#include <iostream>
using namespace std;
typedef long long ll;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n;
int a[102];
ll d[102][21];  // d[i][j] = i까지 도달했을때 j만드는 경우의 수

int main() {
    FASTIO;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    d[1][a[1]] = 1;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= 20; ++j) {
            if (j - a[i] >= 0) d[i][j] += d[i - 1][j - a[i]];
            if (j + a[i] <= 20) d[i][j] += d[i - 1][j + a[i]];
        }
    }

    cout << d[n - 1][a[n]];
    return 0;
}
