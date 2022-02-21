#include <iostream>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int t, n;

int main() {
    FASTIO;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; n != 0; ++i, n /= 2) {
            if (n & 1) cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}
