#include <iostream>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
// 소인수분해
int main() {
    FASTIO;
    int n;
    cin >> n;
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            cout << i << endl;
            n /= i;
        }
    }
    if (n > 1) cout << n;
    return 0;
}
