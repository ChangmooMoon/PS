#include <cstring>
#include <iostream>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n;
int a[1005], d[1005];
// d[i+j] = min(d[i]) + 1(1 <= j <= a[i])

int main() {
    FASTIO;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    memset(d, -1, sizeof(d));

    d[0] = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (d[i] == -1) continue;
        for (int j = 1; j <= a[i]; ++j) {
            if (i + j >= n) break;
            if (d[i + j] == -1 || d[i + j] > d[i] + 1)
                d[i + j] = d[i] + 1;
        }
    }

    cout << d[n - 1];
    return 0;
}
