#include <cstring>
#include <iostream>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n;
int a[1005], d[1005];

int main() {
    FASTIO;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    memset(d, -1, sizeof(d));

    d[0] = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (d[j] == -1 || i - j > a[j]) continue;
            if (d[i] == -1 || d[i] > d[j] + 1)
                d[i] = d[j] + 1;
        }
    }

    cout << d[n - 1];
    return 0;
}
