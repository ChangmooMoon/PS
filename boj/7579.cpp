#include <iostream>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n, m;
int a[100], c[100], d[10001]; // a100 * c100

int main() {
    FASTIO;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        int cost;
        cin >> cost;
        for (int j = 10000; j >= cost; --j) {
            d[j] = max(d[j], d[j - cost] + a[i]);
        }
    }
    for (int i = 0; i <= 10000; ++i) {
        if (d[i] >= m) {
            cout << i;
            return 0;
        }
    }
    return 0;
}
