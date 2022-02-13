#include <algorithm>
#include <iostream>
using namespace std;
#define INF 0x3f3f3f3f
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int a, b, c, x, y;

int main() {
    FASTIO;
    cin >> a >> b >> c >> x >> y;
    int ans = INF;
    for (int i = 0; i <= x + y; ++i) {  // x-i, y-i, 2i
        int p1 = 2 * i * c;
        int p2 = max(0, (x - i) * a);
        int p3 = max(0, (y - i) * b);
        ans = min(ans, p1 + p2 + p3);
    }
    cout << ans;
    return 0;
}
