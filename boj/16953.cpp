#include <iostream>
using namespace std;
typedef long long ll;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int ans = -1;
ll a, b;

void go(ll a, int cnt) {
    if (a > b) return;
    if (a == b) ans = cnt;
    go(a * 2, cnt + 1);
    go(a * 10 + 1, cnt + 1);
}

int main() {
    FASTIO;
    cin >> a >> b;
    go(a, 0);
    if (ans != -1) ++ans;
    cout << ans;

    return 0;
}
