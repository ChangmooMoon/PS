#include <iostream>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int cur, ans, a, b;

int main() {
    FASTIO;
    for (int i = 0; i < 10; ++i) {
        cin >> a >> b;
        cur += b - a;
        if (ans < cur) ans = cur;
    }
    cout << ans;
    return 0;
}
