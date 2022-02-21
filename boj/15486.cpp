#include <iostream>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n;
int t[1500001], p[1500001], d[1500001];

int main() {
    FASTIO;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> t[i] >> p[i];
    }
    for (int i = 0; i < n; ++i) {
        d[i + t[i]] = max(d[i] + p[i], d[i + t[i]]);
        d[i + 1] = max(d[i + 1], d[i]);
    }
    cout << d[n];
    return 0;
}
