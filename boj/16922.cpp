#include <iostream>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
// 브루트포스
// 4^20=1조 이므로 모두 만드는 방식은 쓰면 안됨
// I V X L 조합의 갯수 -> 20^4 {0,0,0,0}
// -> I V X 가 정해지면 L은 n에서 나머지를 뺀 갯수 -> n^3

bool check[50 * 20 + 1];  // 50을 20번쓰는 케이스가 최대
int main() {
    FASTIO;
    int n;
    cin >> n;

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n - i; ++j) {
            for (int k = 0; k <= n - i - j; ++k) {
                int l = n - i - j - k;
                int sum = i + 5 * j + 10 * k + 50 * l;
                check[sum] = true;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= 1000; ++i) {
        if (check[i]) ++ans;
    }

    cout << ans;
    return 0;
}
