#include <algorithm>
#include <iostream>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int t, a[10];
int main() {
    FASTIO;
    cin >> t;
    while (t--) {
        for (int i = 0; i < 10; ++i) {
            cin >> a[i];
        }
        sort(a, a + 10);
        cout << a[7] << endl;
    }
    return 0;
}
