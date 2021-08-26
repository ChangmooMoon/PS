#include <iostream>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n, ans;
bool a[1000002], b[1000002];

int main() {
    FASTIO;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        if (b[i] != a[i]) {
            ++ans;
            b[i] = !b[i];
            b[i + 1] = !b[i + 1];
            b[i + 2] = !b[i + 2];
        }
    }

    cout << ans;
    return 0;
}
