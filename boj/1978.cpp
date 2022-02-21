#include <iostream>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
// 소수찾기, 에라스토테네스의 체
int n, k, ans;
bool check[1001];

int main() {
    FASTIO;
    check[0] = check[1] = true;
    for (int i = 2; i * i <= 1000; ++i) {
        if (!check[i]) {
            for (int j = i * 2; j <= 1000; j += i) {
                check[j] = true;
            }
        }
    }
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> k;
        if (!check[k]) ++ans;
    }
    cout << ans;
    return 0;
}
