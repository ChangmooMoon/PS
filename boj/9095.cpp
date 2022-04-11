#include <iostream>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int t, n, d[11] = {1, 1, 2};

int main() {
    FASTIO;
    for (int i = 3; i < 11; ++i) {
        d[i] = d[i - 3] + d[i - 2] + d[i - 1];
    }
    cin >> t;
    while (t--) {
        cin >> n;
        cout << d[n] << endl;
    }

    return 0;
}
