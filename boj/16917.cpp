#include <iostream>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
#define INF 0x3f3f3f3f

int main() {
    FASTIO;
    int a, b, c, x, y;  // 양념, 후라이드, 반반 가격,
    cin >> a >> b >> c >> x >> y;
    // 반반 2*i개 구매 -> x -i, y-i개 구매
    // 2i * c + max(0, x-i)*a + max(0, y-i) * b = 가격

    int ans = INF;
    for (int i = 0; i <= 100000; ++i) {
        int half = 2 * c * i;
        int seasoning = max(0, (x - i) * a);
        int fried = max(0, (y - i) * b);
        ans = min(ans, half + seasoning + fried);
    }

    cout << ans;
    return 0;
}
